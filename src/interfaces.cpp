#include "interfaces.h"

bool CInterfaces::init()
{
	INIT_INTERFACE(IVEngineClient, engine, "engine.dll", interfaces_names::iv_engine_client);
	INIT_INTERFACE(VClientEntityList, client_entity_list, "client.dll", interfaces_names::v_client_entity_list);
	INIT_INTERFACE(VBaseClient, client, "client.dll", interfaces_names::v_base_client);


	do { this->client_mode = **(IClientMode***)((*(uintptr_t**)this->client)[10] + 0x5); } while (!this->client_mode);


	return true;
}

void CInterfaces::print_interfaces()
{
	PRINT_INTERFACE(this->engine, "IVEngineClient");
	PRINT_INTERFACE(this->client, "VClient");
	PRINT_INTERFACE(this->client_entity_list, "VClientEntityList");
	PRINT_INTERFACE(this->client_mode, "IClientMode");
}
