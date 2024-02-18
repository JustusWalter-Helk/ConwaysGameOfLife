#pragma once

#include <vector>

#include "SDL2/SDL.h"

#include "../Util/Rectangle.h"

namespace Kyuubi {
	class Scene {

	public:
		void draw(SDL_Renderer* renderer);
		std::vector<Rectangle> objects = std::vector<Rectangle>();
		void handleInput();
		void addObject(Rectangle rect);
		void addObject(std::vector<Rectangle> rects);
	};
}