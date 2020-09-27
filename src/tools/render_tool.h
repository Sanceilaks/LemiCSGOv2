#pragma once
#include <singleton.h>
#include <string>
#include <vector>

#include <d3d9.h>
#include <d3dx9.h>
#include <game_sdk/classes/color.h>
#include <interfaces.h>


class RenderTool : public Singleton<RenderTool>
{
private:
	IDirect3DDevice9* device;
	DWORD color;

public:
	RenderTool() {};

	void init(IDirect3DDevice9* device);

	void set_draw_color(const Color& color);

	void draw_filled_box(int x, int y, int w, int h, const Color& color);
	void draw_border_box(int x, int y, int w, int h, const Color& color, int l = 1);
	void draw_text(int x, int y, unsigned long font, const std::string& text, bool centered, Color color);
	void draw_cricle(int x, int y, float R, int sn, Color color);

	void create_font(std::vector<ULONG>& in, const char* font = "Tahoma", int max_size = 100, int flags = (int)FontFlags::FONTFLAG_DROPSHADOW);
	//void render_filled_box(int x, int y, int w, int h, const Color& color);
	//void render_border_box(int x, int y, int w, int h, const Color& color, int l = 1);
};

/*

*/
class DXRender : public Singleton<DXRender>
{
private:
	IDirect3DDevice9* device;
	DWORD color;

public:
	DXRender() {};



};