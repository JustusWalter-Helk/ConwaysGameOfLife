#include "SettingsImGui.h"

	void SettingsImGui::NewFrame(int& margin, float& size, bool& generate) {
		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Simulation Settings", nullptr,ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

		ImGui::SetWindowSize(ImVec2(200, 200));
		ImGui::SetWindowPos(ImVec2(0, 700));
		ImGui::Checkbox("Allow key hold", &allowKeyHold);

		ImGui::InputInt("Cell Margin", &margin);
		ImGui::InputFloat("Size Multiplier", &size);
		if (ImGui::Button("Generate", ImVec2(80, 20))) {
			generate = true;
		}

		if (ImGui::Button("Clear Cell Status")) {
			Game::ClearCellStatus();
		}

		if (ImGui::Button("Clear Cells")) {
			Game::ClearCells();
		}

		ImGui::TextColored(ImVec4(255, 99, 71, 255), "Simulation Status");
		ImGui::Text("Alive cells: %d", aliveCells);
		ImGui::Text("Dead cells: %d", deadCells);

		ImGui::End();
	}
	bool SettingsImGui::allowKeyHold = false;