#include "hack_core.h"
#include "interfaces.h"
#include "hooks/hook_manager.h"

bool CHackCore::init()
{
	//#ifdef DEBUG_CONSOLE
	AllocConsole();
	freopen("CONOUT$", "wb", stdout);
	freopen("CONOUT$", "wb", stderr);
	freopen("CONIN$", "rb", stdin);
	//#endif


	//if (this->fnPreInit_ != nullptr && !this->fnPreInit_())
		//return false;

	//std::cout <<  "          _____            _____                    _____                    _____          \n";
	//std::cout <<  "         /\    \          /\    \                  /\    \                  /\    \         \n";
	//std::cout <<  "        /::\____\        /::\    \                /::\____\                /::\    \        \n";
	//std::cout <<  "       /:::/    /       /::::\    \              /::::|   |                \:::\    \       \n";
	//std::cout <<  "      /:::/    /       /::::::\    \            /:::::|   |                 \:::\    \      \n";
	//std::cout <<  "     /:::/    /       /:::/\:::\    \          /::::::|   |                  \:::\    \     \n";
	//std::cout <<  "    /:::/    /       /:::/__\:::\    \        /:::/|::|   |                   \:::\    \    \n";
	//std::cout <<  "   /:::/    /       /::::\   \:::\    \      /:::/ |::|   |                   /::::\    \   \n";
	//std::cout <<  "  /:::/    /       /::::::\   \:::\    \    /:::/  |::|___|______    ____    /::::::\    \  \n";
	//std::cout <<  " /:::/    /       /:::/\:::\   \:::\    \  /:::/   |::::::::\    \  /\   \  /:::/\:::\    \ \n";
	//std::cout <<  "/:::/____/       /:::/__\:::\   \:::\____\/:::/    |:::::::::\____\/::\   \/:::/  \:::\____\\\n";
	//std::cout <<  "\:::\    \       \:::\   \:::\   \::/    /\::/    / ~~~~~/:::/    /\:::\  /:::/    \::/    /\n";
	//std::cout <<  " \:::\    \       \:::\   \:::\   \/____/  \/____/      /:::/    /  \:::\/:::/    / \/____/ \n";
	//std::cout <<  "  \:::\    \       \:::\   \:::\    \                  /:::/    /    \::::::/    /          \n";
	//std::cout <<  "   \:::\    \       \:::\   \:::\____\                /:::/    /      \::::/____/           \n";
	//std::cout <<  "    \:::\    \       \:::\   \::/    /               /:::/    /        \:::\    \           \n";
	//std::cout <<  "     \:::\    \       \:::\   \/____/               /:::/    /          \:::\    \          \n";
	//std::cout <<  "      \:::\    \       \:::\    \                  /:::/    /            \:::\    \         \n";
	//std::cout <<  "       \:::\____\       \:::\____\                /:::/    /              \:::\____\        \n";
	//std::cout <<  "        \::/    /        \::/    /                \::/    /                \::/    /        \n";
	//std::cout <<  "         \/____/          \/____/                  \/____/                  \/____/         \n";
	//std::cout <<  "                                                                                            \n";

	std::cout << "[L]\tCapturing interfaces" << std::flush;
	if (CInterfaces::get().init())
		std::cout << "\tOK!" << std::endl;
	else
		return false;
	CInterfaces::get().print_interfaces();
	std::cout << "\n[L]\tHooking functions" << std::flush;
	if (HookManager::get().setup())
		std::cout << "\tOK!" << std::endl;
	else
		return false;

	//if (this->fnPostInit_ != nullptr && !this->fnPostInit_())
		//return false;
	return true;
}

bool CHackCore::shutdown()
{
	return false;
}