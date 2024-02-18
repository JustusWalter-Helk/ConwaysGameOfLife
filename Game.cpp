#include "./Core/Window.h"
#include "./Core/Renderer.h"
#include "./Core/Scene.h"

#include "./Util/Rectangle.h"

#include <iostream>

using namespace Kyuubi;

int main() {
	bool running = true;

	Kyuubi::Scope<Kyuubi::Window> window = Kyuubi::Window::Create(Kyuubi::WindowProps());

	SDL_Window* nativeWindow = static_cast<SDL_Window*>(window->GetNativeWindow());

	SDL_Renderer* renderer = Kyuubi::Renderer::Init(Kyuubi::RenderSettings(nativeWindow));

	Kyuubi::Scene scene = Kyuubi::Scene();
	
	int height = window->GetHeight();
	int width = window->GetWidth();

	int xOffset = 0;
	int yOffset = 0;

	for (int i = 0; i < 1000; i++) {
		Kyuubi::Rectangle rect = Rectangle();
		rect.color = Color(81,183,203, 1);

		rect.SizeX = 40;
		rect.SizeY = 40;

		if ((xOffset * rect.SizeX) > width) {
			yOffset += 1;
			xOffset = 0;
		}

		rect.PosX = xOffset * rect.SizeX;
		rect.PosY = yOffset * rect.SizeY;

		scene.addObject(rect);

		KYEngine(xOffset);

		xOffset++;
	}

	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				SDL_Quit();
			}
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_RenderClear(renderer);

		scene.draw(renderer);
	}

	std::cin.get();

	return 0;
}