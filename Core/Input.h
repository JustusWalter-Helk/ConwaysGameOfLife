#pragma once

#include <vector>
#include "SDL2/SDL.h"

namespace Kyuubi {
	class Input {
	public:
		static void setWindow(SDL_Window* window);

		static bool isKeyHold(SDL_Scancode keyCode);
		static bool isKeyPressed(SDL_Scancode keyCode);

		static void keyDown(SDL_Scancode keyCode);
		static void keyUp(SDL_Scancode keyCode);

		static void endFrame();

		static bool disableHoldCheck;
	private:
		static std::vector<bool> holdedKeys;
		static std::vector<bool> pressedKeys;
		static std::vector<bool> prevKeyHeld;
		static std::vector<bool> prevKeyPressed;

		static SDL_Window* window;
	};
}