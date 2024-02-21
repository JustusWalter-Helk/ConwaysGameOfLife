#pragma once

#include <vector>

#include "SDL2/SDL.h"

#include "Object.h"

namespace Kyuubi {
	class Scene {
	public:
		virtual void draw(SDL_Renderer* renderer);
		std::vector<Object> objects = std::vector<Object>();
		virtual void addObject(Object& object);
		virtual void addObject(std::vector<Object> newObjects);
	};
}