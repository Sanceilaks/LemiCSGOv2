#include "create_move_hook.h"
#include <game_sdk/entitys/base_player.h>
#include "hook_manager.h"

#include <Windows.h>

#include <features/legit_bot/legit_bot.h>

#define	FL_ONGROUND				(1<<0)

bool __stdcall create_move_hook::hook(int frame_time, CUserCmd* ucmd)
{
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		LegitBot::get().work(ucmd);
	}

	HookManager::get().create_move_original(CInterfaces::get().client_mode, frame_time, ucmd);

	if (!ucmd)
		return false;

	CBasePlayer* local_player = CBasePlayer::get_local_player();

	if (ucmd->buttons & IN_JUMP && !(local_player->get_flags() & (int)FL_ONGROUND))
		ucmd->buttons &= ~IN_JUMP;

    return false;
}
