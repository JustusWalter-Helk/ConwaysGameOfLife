#pragma once

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include <SDL2/SDL.h>

#include "DearImGui.h"
#include "../Base.h"

namespace Kyuubi {
	class DearImGui {
	public:
		static void Initialize(SDL_Window*, SDL_Renderer*);
		static bool ProcessEvent(SDL_Event*);
	};

	class ImGuiWindow {
	public:
		virtual void NewFrame();
	};
}