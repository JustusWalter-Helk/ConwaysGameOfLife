#include "InfoImGui.h"

void InfoImGui::NewFrame() {

	ImGui::Begin("Info", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus);

	ImGui::SetWindowSize(ImVec2(500, 200), 0);
	ImGui::SetWindowPos(ImVec2(0, 0));
	

	ImGui::TextColored(ImVec4(255,255,0,1), "Press F to advance the simulation");

	ImGui::End();
}
