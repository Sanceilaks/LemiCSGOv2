#include "legit_bot.h"

#include <interfaces.h>

#include <globals.h>
#include <game_sdk/entitys/local_player.h>

CBasePlayer* LegitBot::get_closest(Math::QAngle& view_angels)
{
	CLocalPlayer* local_player = CLocalPlayer::get_local_player();
	CBasePlayer* best = nullptr;

	float best_fov = FLT_MAX;

	for (size_t i = 0; i <= 64; i++)
	{
		CBasePlayer* ply = (CBasePlayer*)CBasePlayer::get_by_index(i);

		if (!ply || !ply->is_alive() || ply == local_player || ply->is_dormant())
			continue;

		if (ply->get_client_class()->ClassId != class_ids::ccsplayer)
			continue;


		if (G::get().check_team)
			if (ply->get_team_num() == local_player->get_team_num())
				continue;

		float fov = local_player->get_fov_to_player(view_angels + local_player->get_aim_punch_angel() * 2.f, ply);

		if (fov < best_fov && fov < G::get().fov)
			best_fov = fov, best = ply;

	}

	return best;
}

void LegitBot::work(CUserCmd* ucmd)
{
	CLocalPlayer* local_player = CLocalPlayer::get_local_player();
	if (!local_player)
		return;

	Math::QAngle view_angel;
	CInterfaces::get().engine->get_viewangles(view_angel);

	CBasePlayer* best = this->get_closest(view_angel);
	if (!best)
		return;


	Math::QAngle ang = Math::CalcAngel(local_player->get_eye_pos(), best->get_entity_bone((ECSPlayerBones)8)) - local_player->get_aim_punch_angel() * 2;

	smooth(view_angel, ang, G::get().f_smooth);

	if (ucmd->viewangles != ang)
		ucmd->viewangles = ang;

	CInterfaces::get().engine->set_viewangles(ang);

}

void LegitBot::smooth(Math::QAngle& view_angel, Math::QAngle& angel, float value)
{
	angel = (view_angel + (angel - view_angel).Clamped() / value).Clamped();
}
