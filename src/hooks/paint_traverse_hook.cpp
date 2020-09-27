#include "paint_traverse_hook.h"
#include "hook_manager.h"
#include <interfaces.h>

#include <game_sdk/fnv.h>
#include <tools/render_tool.h>

#include <globals.h>

#include <features/esp/esp.h>

static bool is_init = false;

void init()
{
	RenderTool::get().create_font(G::get().dFont);
}

void __stdcall paint_traverse_hook::hook(unsigned int panel, bool force_repaint, bool allow_force)
{
	if (!is_init)
		init();

	const char* pname = CInterfaces::get().i_panel->get_panel_name(panel);
	auto pnh = fnv::hash(pname);

	//std::cout << "Panel: " << pname << std::endl;

	int screenw, screenh; CInterfaces::get().engine->get_screen_size(screenw, screenh);

	switch (pnh)
	{
	case fnv::hash("MatSystemTopPanel"):
		RenderTool::get().draw_text(10, 10, G::get().dFont[16], "LemiCSGO", false, Color::White());

		ESP::get().draw();

		//RenderTool::get().draw_cricle(screenw / 2, screenh / 2, G::get().aim->fov, 120, Color::Black());

		break;
	case fnv::hash("FocusOverlayPanel"):
		break;
	}

	HookManager::get().paint_traverse_original(CInterfaces::get().i_panel, panel, force_repaint, allow_force);
}
