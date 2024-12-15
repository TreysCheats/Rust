#pragma once
#include "../../../common.hpp"
#include "drawing.hpp"

namespace menu {
	inline ImGuiColorEditFlags cef = ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip;
	inline bool active = true, inited = false;

	void init();
	void ui();
	void render();

	inline int tab = 0;
	inline int aTab, vTab, mTab, cTab;
}