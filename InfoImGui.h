#pragma once
#include "./Imgui/DearImGui.h"

class InfoImGui : public Kyuubi::ImGuiWindow {
public:
	void NewFrame() override;
};

