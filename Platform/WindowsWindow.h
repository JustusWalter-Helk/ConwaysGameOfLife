#pragma once

#include "../Core/Window.h"
#include "Platform.h"
#include "../Core/Renderer.h"

#include "iostream"

#include "../ImGui/DearImGui.h"

#include "imgui.h"
#include "SDL2/SDL.h"

namespace Kyuubi {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		~WindowsWindow() override;

		void OnUpdate() override;

		void* GetNativeWindow() const override {
			return static_cast<void*>(window);
		}

		uint32_t GetWidth() const override;
		uint32_t GetHeight() const override;

		void SetVSync(bool enabled) override;
		void IsVsync() const override;

	private:
		void Init(const WindowProps& props);

		SDL_Window* window = nullptr;

		WindowProps windowProperties;

		bool vsync = false;
	};
}