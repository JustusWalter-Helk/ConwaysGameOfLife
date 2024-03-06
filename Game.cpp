#include "./Core/Window.h"
#include "./Core/Renderer.h"

#include "./Core/Input.h"
#include "./ImGui/DearImGui.h"
#include "SettingsImGui.h"
#include "InfoImGui.h"

#include "Cell.h"
#include "SimulationScene.h"

#include <iostream>

#include "Game.h"

using namespace Kyuubi;

void GenerateCells(int height, int width, int cellSize, int cellMargin, SimulationScene& scene) {
	int numRows = height / (cellSize + cellMargin);
	int numColumns = width / (cellSize + cellMargin);

	for (int column = 0; column < numColumns; column++) {
		for (int row = 0; row < numRows; row++) {
			Cell cell;
			cell.row = row;
			cell.column = column;

			cell.color = Color(40, 122, 112, 255);

			cell.SizeX = cellSize;
			cell.SizeY = cellSize;

			cell.PosX = column * (cellSize + cellMargin);
			cell.PosY = row * (cellSize + cellMargin);

			scene.addObject(cell);
		}
	}
}

static SimulationScene scene = SimulationScene();

void Game::ClearCells() {
	scene.cells.clear();
	Cell cell = Cell();
	scene.cells.push_back(cell);
}

void Game::ClearCellStatus() {
	for (Cell& cell : scene.cells) {
		cell.Enabled = false;
	}
}

int main() {
	bool running = true;

	Kyuubi::Scope<Kyuubi::Window> window = Kyuubi::Window::Create(Kyuubi::WindowProps());

	SDL_Window* nativeWindow = static_cast<SDL_Window*>(window->GetNativeWindow());

	SDL_Renderer* renderer = Kyuubi::Renderer::Init(Kyuubi::RenderSettings(nativeWindow));

	bool generate = false;

	int height = window->GetHeight();
	int width = window->GetWidth();

	KYEngine(width);
	KYEngine(width);

	int margin = 5;

	float size = 1.0f;

	int cellSize = 40 * size;
	int cellMargin = 5;

	float cameraX = 0.0f;
	float cameraY = 0.0f;

	int mouseX, mouseY;

	Cell cell = Cell();

	scene.addObject(cell);

	DearImGui::Initialize(nativeWindow, renderer);
	SettingsImGui settingsWindow;
	settingsWindow.NewFrame(cellMargin, size, generate);
	InfoImGui infoWindow;
	infoWindow.NewFrame();

	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (!DearImGui::ProcessEvent(&event)) {
				if (event.type == SDL_KEYDOWN) {
					Input::keyDown(event.key.keysym.scancode);
				}
				else if (event.type == SDL_KEYUP) {
					Input::keyUp(event.key.keysym.scancode);
				}
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					SDL_GetMouseState(&mouseX, &mouseY);
					scene.handleInput(mouseX, mouseY);

					if (Cell::hoveredCell) {
						Cell& cell = *Cell::hoveredCell;
						if (event.button.button == SDL_BUTTON_LEFT) {
							cell.Enabled = true;
						}
						if (event.button.button == SDL_BUTTON_RIGHT) {
							cell.Enabled = false;
						}
					}
				}

				if (event.type == SDL_QUIT) {
					running = false;
					SDL_Quit();
				}
			}
		}

		if (generate) {
			scene.cells.clear();

			int cellSize = 40 * size;

			GenerateCells(height, width, cellSize, cellMargin, scene);
			generate = false;
		}

		if (Input::isKeyPressed(SDL_SCANCODE_W)) {
			cameraX += 1;
			Conway(cameraX);
		}

		settingsWindow.NewFrame(cellMargin, size, generate);
		infoWindow.NewFrame();
		Input::disableHoldCheck = settingsWindow.allowKeyHold;

		scene.getCellCount(settingsWindow.aliveCells, settingsWindow.deadCells);

		if (Input::isKeyPressed(SDL_SCANCODE_F)) {
			scene.doSimulationStep();
		}

		SDL_SetRenderDrawColor(renderer, 22, 46, 37, 255);
		SDL_RenderClear(renderer);

		scene.draw(renderer);
		

		Input::endFrame();
	}

	std::cin.get();

	return 0;
}