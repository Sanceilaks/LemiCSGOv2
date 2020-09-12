#include "command_executor.h"
#include "interfaces.h"
#include <game_sdk/entitys.h>

void CCommandExecutor::execute(const std::string& cmd)
{
	if (cmd == "ingame")
	{
		std::cout << CInterfaces::get().engine->is_in_game() << std::endl;
	}
	else if (cmd == "screensize")
	{
		int w, h;
		CInterfaces::get().engine->get_screen_size(w, h);
		std::cout << w << " x " << h << std::endl;
	}
	else if (cmd == "getlpi")
	{
		std::cout << CInterfaces::get().engine->get_local_player() << std::endl;
	}
	else if (cmd == "geth")
	{
		auto ent = (
			(CBasePlayer*)
			(CInterfaces::get().client_entity_list->get_entity_by_index(
			CInterfaces::get().engine->get_local_player()
			)));

		std::cout << ent->get_health() << "\t" << ent->get_flags() << "\t" << ent->get_team_num() << std::endl;
	}
	else if (cmd == "getclasses")
	{
		auto r = reinterpret_cast<DWORD>(CInterfaces::get().client->get_all_classes());
		std::cout << r << std::endl;
	}
}
