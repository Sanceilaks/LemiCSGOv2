#include "hack_core.h"
#include "interfaces.h"
#include "hooks/hook_manager.h"
#include "globals.h"


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


	std::cout << "[L]\tCapturing interfaces" << std::flush;
	if (CInterfaces::get().init())
		std::cout << "\tOK!" << std::endl;
	else
		return false;
	CInterfaces::get().print_interfaces();

	G::get().font = CInterfaces::get().i_surface->font_create();

	CInterfaces::get().i_surface->set_font_glyph(G::get().font, "Tahoma", 12, 500, 0, 0, (int)FontFlags::FONTFLAG_DROPSHADOW);

	//console::log("[setup] render initialized!\n");


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