#include "create_move_hook.h"
#include <game_sdk/entitys/base_player.h>
#include "hook_manager.h"

#define	FL_ONGROUND				(1<<0)

bool __stdcall create_move_hook::hook(int frame_time, CUserCmd* ucmd)
{
	auto ret = HookManager::get().create_move_original(CInterfaces::get().client_mode, frame_time, ucmd);

	if (!ucmd)
		return false;

	CBasePlayer* local_player = CBasePlayer::get_local_player();


	std::cout << ucmd->buttons << "     " << (int)IN_JUMP << std::endl;
	if (ucmd->buttons & IN_JUMP && !(local_player->get_flags() & (int)FL_ONGROUND))
	{
		std::cout << "Jump!" << std::endl;
		ucmd->buttons &= ~IN_JUMP;
	}

	std::cout << "VE: " << ucmd->viewangles.x << " " << ucmd->viewangles.y << " " << ucmd->viewangles.z << std::endl;
    return ret;
}
