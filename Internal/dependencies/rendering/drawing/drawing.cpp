#include "drawing.hpp"

void drawing::drawLine(ImVec2 from, ImVec2 to, ImColor color) {
	ImGui::GetForegroundDrawList()->AddLine(from, to, color);
	ImGui::GetBackgroundDrawList()->AddLine(from, to, color);
}
void drawing::drawCircle(ImVec2 center, float radius, ImColor color) {
	ImGui::GetForegroundDrawList()->AddCircle(center, radius, color, 100);
}
void drawing::drawText(ImVec2 pos, ImColor color, const char* text) {
	ImGui::GetForegroundDrawList()->AddText(pos, color, text);
}
void drawing::drawCrosshair(ImColor color) {
	float gap = 1, size = 5;

	drawing::drawLine(ImVec2(screenCenter.x - size - gap, screenCenter.y), ImVec2(screenCenter.x - gap, screenCenter.y), color);
	drawing::drawLine(ImVec2(screenCenter.x + gap + 1, screenCenter.y), ImVec2(screenCenter.x + size + gap + 1, screenCenter.y), color);

	drawing::drawLine(ImVec2(screenCenter.x, screenCenter.y - size - gap), ImVec2(screenCenter.x, screenCenter.y - gap), color);
	drawing::drawLine(ImVec2(screenCenter.x, screenCenter.y + gap + 1), ImVec2(screenCenter.x, screenCenter.y + size + gap + 1), color);
}