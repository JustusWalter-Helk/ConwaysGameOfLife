#include "./Core/Window.h"
#include "./Core/Renderer.h"

#include "Cell.h"
#include "SimulationScene.h"

#include <iostream>

using namespace Kyuubi;

int main() {
	bool running = true;

	Kyuubi::Scope<Kyuubi::Window> window = Kyuubi::Window::Create(Kyuubi::WindowProps());

	SDL_Window* nativeWindow = static_cast<SDL_Window*>(window->GetNativeWindow());

	SDL_Renderer* renderer = Kyuubi::Renderer::Init(Kyuubi::RenderSettings(nativeWindow));

	SimulationScene scene = SimulationScene();
	
	int height = window->GetHeight();
	int width = window->GetWidth();

	KYEngine(width);
	KYEngine(width);

	int xOffset = 0;
	int yOffset = 0;

	int margin = 5;

	for (int i = 0; i < 1000; i++) {
		Cell cell = Cell();
		cell.color = Color(40,122,112, 255);

		cell.SizeX = 40;
		cell.SizeY = 40;

		KYEngine((xOffset * (cell.SizeX + margin) + cell.SizeX));

		if ((xOffset * (cell.SizeX) + cell.SizeX) >= width) {
			yOffset += 1; // Move to the next row
			xOffset = 0; // Reset xOffset for the new row
		}

		cell.PosX = xOffset * (cell.SizeX + margin);
		cell.PosY = yOffset * (cell.SizeY + margin);

		scene.addObject(cell);

		KYEngine(xOffset);

		xOffset++;
	}

	int mouseX, mouseY;

	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&mouseX, &mouseY);
				scene.handleInput(mouseX, mouseY);

				Cell& cell = *Cell::hoveredCell;
				if (event.button.button == SDL_BUTTON_LEFT) {
					cell.Enabled = true;
				}
				if (event.button.button == SDL_BUTTON_RIGHT) {
					cell.Enabled = false;
				}
			}

			if (event.type == SDL_QUIT) {
				running = false;
				SDL_Quit();
			}
		}

		SDL_SetRenderDrawColor(renderer, 22, 46, 37, 255);
		SDL_RenderClear(renderer);

		scene.draw(renderer);
	}

	std::cin.get();

	return 0;
}