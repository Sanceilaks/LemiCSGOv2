#include "hack_core.h"
#include "interfaces.h"

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


	std::cout << "[L]	Capturing interfaces" << std::flush;
	if (CInterfaces::get().init())
		std::cout << "	OK!" << std::endl;
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

void CHackCore::setPreInit(init_callback preInitFuncion)
{
	this->fnPreInit_ = preInitFuncion;
}
void CHackCore::setPostInit(init_callback prePostFuncion)
{
	this->fnPostInit_ = prePostFuncion;
}