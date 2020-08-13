#include "command_executor.h"
#include "interfaces.h"

void CCommandExecutor::execute(const std::string& cmd)
{
	if (cmd == "ingame")
	{
		std::cout << CInterfaces::get().engine->isInGame() << std::endl;
	}
}
