#pragma once

#include "SDL2/SDL.h"

namespace Kyuubi {
	struct RenderSettings {
		SDL_Window* Window;
		bool Vsync;
		int DriverIndex;
		uint32_t Flags;

		RenderSettings(SDL_Window* window = nullptr,
			bool vsync = false,
			int driverIndex = -1,
			uint32_t flags = 0)
			: Window(window), Vsync(vsync), DriverIndex(driverIndex), Flags(flags) {}
	};
	class Renderer {
	public:
		static SDL_Renderer* Init(const RenderSettings& settings);
	};
}