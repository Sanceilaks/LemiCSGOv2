#pragma once
#include <singleton.h>
#include "hooks.h"


class HookManager : public Singleton<HookManager>
{
public:
	create_move_hook::fn create_move_original = nullptr;
	paint_traverse_hook::fn paint_traverse_original = nullptr;


	bool setup();
	void remove();
};