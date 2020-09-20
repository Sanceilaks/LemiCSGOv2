#include "esp.h"

#include <math/v_matrix.h>
#include <math/game_math.h>
#include <game_sdk/entitys/local_player.h>
#include <globals.h>


#include <algorithm>


//RECT get_box(CBaseEntity* ent)
//{
//	RECT recy{};
//	auto collideable = ent->get_collideable();
//
//	
//}

void draw_filled_rect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, Color color) 
{
	CInterfaces::get().i_surface->set_drawing_color(color.r(), color.g(), color.b(), color.a());
	CInterfaces::get().i_surface->draw_filled_rectangle(x, y, width, height);
}

void draw_text(std::int32_t x, std::int32_t y, unsigned long font, std::string text, bool centered, Color color) {
	const auto surface = CInterfaces::get().i_surface;
	wchar_t temp[128];
	int text_width, text_height;
	if (MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, temp, 128) > 0) {
		surface->draw_text_font(font);
		if (centered) {
			surface->get_text_size(font, temp, text_width, text_height);
			surface->draw_text_pos(x - text_width / 2, y);
		}
		else
			surface->draw_text_pos(x, y);
		surface->set_text_color(color.r(), color.g(), color.b(), color.a());
		surface->draw_render_text(temp, wcslen(temp));
	}
}


inline void draw_box(CBasePlayer* ent)
{
	auto get_box = [](Math::CVector feet, Math::CVector head) -> RECT {
		RECT ret;

		auto h_ = fabs(head.y - feet.y);
		auto w_ = h_ / 2.0f;

		ret.left = (feet.x - w_ * 0.5f);
		ret.right = ((LONG)ret.left + (LONG)w_);
		ret.bottom = ((LONG)feet.y > (LONG)head.y ? (LONG)(feet.y) : (LONG)(head.y));
		ret.top = ((LONG)feet.y > (LONG)head.y ? (LONG)(head.y) : (LONG)(feet.y));

		return ret;
	};

	CLocalPlayer* local_player = CLocalPlayer::get_local_player();

	Math::CVector v_origin = ent->get_origin();
	Math::CVector v_head = ent->get_entity_bone(head_0);

	v_head += 15.0f;

	Math::CVector v_screen_origin, v_screen_head;

	if (Math::WorldToScreen(v_head, v_screen_head) && Math::WorldToScreen(v_origin, v_screen_origin))
	{
		auto box = get_box(v_screen_origin, v_screen_head);

		float x = box.left; float y = box.top;
		float w = box.right - box.left; float h = box.bottom - box.top;

		draw_filled_rect(x, y, w, h, Color(255, 0, 0, 100));
		//draw_text(x, y, G::get().font, ent->get_name(), true, Color::White());
	}
}

void ESP::draw()
{
	if (!CInterfaces::get().engine->is_in_game())
		return;


	//std::cout << "Getting local_player" << std::endl;

	CLocalPlayer* local_player = CLocalPlayer::get_local_player();

	if (!local_player)
		return;

	//std::cout << "local_player exist" << std::endl;

	for (size_t i = 0; i <= CInterfaces::get().client_entity_list->get_highest_enetity_index(); ++i)
	{
		CBasePlayer* ply = (CBasePlayer*)CBasePlayer::get_by_index(i);

		if (!ply || !ply->is_alive() || ply == local_player || ply->is_dormant())
			continue;

		if (ply->get_client_class()->ClassId != class_ids::ccsplayer)
			continue;

		if (G::get().check_team)
			if (ply->get_team_num() == local_player->get_team_num())
				continue;

		//std::cout << ply << std::endl;

		draw_box(ply);
	}
}
