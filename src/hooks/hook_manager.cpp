#include <MinHook.h>


#include "hook_manager.h"
#include "interfaces.h"


inline unsigned int get_virtual(void* _class, unsigned int index) { return static_cast<unsigned int>((*static_cast<int**>(_class))[index]); }

bool HookManager::setup()
{
    const auto create_move_target = reinterpret_cast<void*>(get_virtual(CInterfaces::get().client_mode, 24));
    const auto paint_traverse_target = reinterpret_cast<void*>(get_virtual(CInterfaces::get().i_panel, 41));

    if (MH_Initialize() != MH_OK)
        return false;

    if (MH_CreateHook(create_move_target, &create_move_hook::hook, reinterpret_cast<void**>(&this->create_move_original)) != MH_OK) 
    { std::cout << "CreateMove" << " setup error\n"; return false; }

    if (MH_CreateHook(paint_traverse_target, &paint_traverse_hook::hook, reinterpret_cast<void**>(&this->paint_traverse_original)) != MH_OK)
    { std::cout << "paint_traverse" << " setup error\n"; return false; }

    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
        return false;

    return true;
}

void HookManager::remove()
{
    MH_Uninitialize();
    MH_DisableHook(MH_ALL_HOOKS);
}
