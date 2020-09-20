#include "paint_traverse_hook.h"
#include "hook_manager.h"
#include <interfaces.h>

#include <game_sdk/fnv.h>

#include <globals.h>

#include <features/esp/esp.h>



void render_text(std::int32_t x, std::int32_t y, unsigned long font, std::string text, bool centered, Color color) {
	const auto surface = CInterfaces::get().i_surface;
	wchar_t temp[128];
	int text_width, text_height;
	if (MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, temp, 128) > 0) {
		surface->draw_text_font(font);
		if (centered) {
			surface->get_text_size(font, temp, text_width, text_height);
			surface->draw_text_pos(x - text_width / 2, y);
		}
		else
			surface->draw_text_pos(x, y);
		surface->set_text_color(color.r(), color.g(), color.b(), color.a());
		surface->draw_render_text(temp, wcslen(temp));
	}
}


void __stdcall paint_traverse_hook::hook(unsigned int panel, bool force_repaint, bool allow_force)
{
	const char* pname = CInterfaces::get().i_panel->get_panel_name(panel);
	auto pnh = fnv::hash(pname);

	//std::cout << "Panel: " << pname << std::endl;

	switch (pnh)
	{
	case fnv::hash("MatSystemTopPanel"):
		render_text(10, 10, G::get().font, "LemiCSGO", false, Color::White());
		ESP::get().draw();

		break;
	case fnv::hash("FocusOverlayPanel"):
		break;
	}

	HookManager::get().paint_traverse_original(CInterfaces::get().i_panel, panel, force_repaint, allow_force);
}
