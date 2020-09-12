#pragma once
#include "singleton.h"
#include "include_all_interfaces.h"
#include "tools/mem_tools.h"
#include <vector>

#define CIINTERNAL

#ifdef CIINTERNAL
#define ADD_INTERFACE( interfaceType, engineInterfaceName ) interfaceType* engineInterfaceName = nullptr;
#define INIT_INTERFACE( interfaceType,  engineInterfaceName, module_, name_ ) this->engineInterfaceName = (interfaceType*)CMemTools::get_interface(module_, name_);

#ifdef DEBUG_CONSOLE
#define PRINT_INTERFACE( interface_, interfaceName) std::cout << "[I]\t" << interfaceName << "\t" << reinterpret_cast<DWORD>(interface_) << std::endl;

#elif DEBUG_CSGO
#define PRINT_INTERFACE( interface_ )
#endif

#endif



namespace interfaces_names
{
	static const char* iv_engine_client = "VEngineClient014";
	static const char* v_client_entity_list = "VClientEntityList003";
	static const char* v_base_client = "VClient018";
}


class CInterfaces : public Singleton<CInterfaces>
{
public:
	ADD_INTERFACE(IVEngineClient, engine);
	ADD_INTERFACE(VClientEntityList, client_entity_list);
	ADD_INTERFACE(VBaseClient, client);
	ADD_INTERFACE(IClientMode, client_mode);

	bool init();
	bool shutdown();
	void print_interfaces();
};

#undef CIINTERNAL