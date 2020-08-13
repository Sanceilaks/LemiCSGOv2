#pragma once
#include "singleton.h"
#include "include_all_interfaces.h"
#include "mem_tools.h"
#include <vector>

#define CIINTERNAL

#ifdef CIINTERNAL
#define ADD_INTERFACE( interfaceType, engineInterfaceName ) interfaceType* engineInterfaceName = nullptr;
#define INIT_INTERFACE( interfaceType,  engineInterfaceName, module_, name_ ) this->engineInterfaceName = (interfaceType*)CMemTools::getInterface(module_, name_);

#ifdef DEBUG_CONSOLE
#define PRINT_INTERFACE( interface_, interfaceName) std::cout << interfaceName << "		" << reinterpret_cast<DWORD>(interface_) << std::endl;

#elif DEBUG_CSGO
#define PRINT_INTERFACE( interface_ )
#endif

#endif




namespace interfaces_names
{
	static const char* iv_engine_client = "VEngineClient014";
}


class CInterfaces : public Singleton<CInterfaces>
{
public:
	ADD_INTERFACE(IVEngineClient, engine);

	bool init();
	bool shutdown();
	void printInterfaces();
};

#undef CIINTERNAL