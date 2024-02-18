#include "Scene.h"

#include "SDL2/SDL.h"
	
	void Kyuubi::Scene::draw(SDL_Renderer* renderer) {
		for (Rectangle rect : objects) {
			SDL_SetRenderDrawColor(renderer, rect.color.r, rect.color.g, rect.color.b, rect.color.a);

			SDL_Rect sdlrect;
			sdlrect.x = rect.PosX;
			sdlrect.y = rect.PosY;
			sdlrect.w = rect.SizeX;
			sdlrect.h = rect.SizeY;

			SDL_RenderFillRect(renderer, &sdlrect);
		}
		SDL_RenderPresent(renderer);
	}

	void Kyuubi::Scene::handleInput() {

	}

	void Kyuubi::Scene::addObject(Rectangle rect) {
		objects.push_back(rect);
	}

	void Kyuubi::Scene::addObject(std::vector<Rectangle> rects) {
		objects.insert(objects.end(), rects.begin(), rects.end());
	}