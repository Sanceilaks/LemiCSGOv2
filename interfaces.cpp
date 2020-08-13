#include "interfaces.h"

#define CIINTERNAL

bool CInterfaces::init()
{
	INIT_INTERFACE(IVEngineClient, engine, "engine.dll", interfaces_names::iv_engine_client);

	return true;
}

void CInterfaces::printInterfaces()
{
	PRINT_INTERFACE(this->engine, "IVEngineClient");
}
