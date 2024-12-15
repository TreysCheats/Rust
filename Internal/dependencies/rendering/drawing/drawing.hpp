#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include "../../../dependencies/rendering/kiero/kiero.h"
#include "../../../dependencies/rendering/imgui/imgui.h"
#include "../../../dependencies/rendering/imgui/imgui_impl_win32.h"
#include "../../../dependencies/rendering/imgui/imgui_impl_dx11.h"
#include "../../../dependencies/rendering/imgui/imgui_internal.h"

namespace drawing {
	inline ImVec2 screenCenter;

	void drawLine(ImVec2 from, ImVec2 to, ImColor color);
	void drawCircle(ImVec2 center, float radius, ImColor color);
	void drawText(ImVec2 pos, ImColor color, const char* text);
	void drawCrosshair(ImColor color);
}