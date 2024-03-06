#pragma once
#include "./ImGui/DearImGui.h"

#include "./Game.h"

	class SettingsImGui : public Kyuubi::ImGuiWindow {
	public:
		void NewFrame(int& margin, float& size, bool& generate);
		static bool allowKeyHold;

		int aliveCells;
		int deadCells;
	};