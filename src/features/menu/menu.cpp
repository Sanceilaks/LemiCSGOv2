#include "menu.h"

#define IMGUI_DISABLE_OBSOLETE_FUNCTIONS

#include <imgui/imgui.h>

#include <globals.h>

#include <iostream>

static bool esp = false;
static bool aim = false;

void Menu::draw()
{
	if (!this->b_open)
		return;

	ImGui::Begin("LemiProject");

	ImGui::Checkbox("AIM", &G::get().aim->enable);
	ImGui::SliderInt("Fov", &G::get().aim->fov, 1, 360, "||%d||");
	ImGui::SliderInt("Smooth", &G::get().aim->smooth, 1, 100, "||%d||");
	ImGui::Spacing();
	ImGui::Checkbox("ESP", &G::get().esp->enable);

	ImGui::End();
}
