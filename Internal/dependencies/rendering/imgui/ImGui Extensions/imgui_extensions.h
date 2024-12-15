#include "../../../../common.hpp"

// Changes to ImGui:
	// imgui.h:
		// ImColor(const float color[4]) { Value = ImVec4(color[0], color[1], color[2], color[3]); }
	// imgui_widgets.cpp:
		// ImGui::SliderScalar:
			// -5 to ImVec2.y in frame_bb
			// -3 to ImVec2.y in RenderText
			// Render grab changed to:
				// window->DrawList->AddRectFilled(frame_bb.Min, grab_bb.Max + ImVec2(0,2), GetColorU32(g.ActiveId == id ? ImGuiCol_SliderGrabActive : ImGuiCol_SliderGrab), style.GrabRounding);
		// ImGui::Checkbox:
			// -5 to ImVec2.x and ImVec2.y in check_bb
			// -3 to ImVec2.y in label_pos   OR   -3 in the ImVec2.y in RenderText
			// RenderCheckMark changed to:
				// RenderFrame(check_bb.Min, check_bb.Max, ImColor(0.65f, 0.04f, 0.18f, 1.00f), true, style.FrameRounding);
		// ImGui::ColorEdit4:
			// -5 to square_sz
			// add ImVec2(15,15) to ColorButton("##ColorButton", col_v4, flags)
			// -3 to ImVec2.y in window->DC.CursorPos

namespace ImGui_Extensions {
	inline void TextCentered(std::string text) {
		auto ww = ImGui::GetWindowSize().x;
		auto tw = ImGui::CalcTextSize(text.c_str()).x;

		ImGui::SetCursorPosX((ww - tw) * 0.5f);
		ImGui::Text(text.c_str());
	}
	inline void HelpMarker(const char* desc)
	{
		ImGui::TextDisabled("[?]");
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
			ImGui::TextUnformatted(desc);
			ImGui::PopTextWrapPos();
			ImGui::EndTooltip();
		}
	}
}