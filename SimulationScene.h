#pragma once
#include "./Core/Scene.h"

#include "Cell.h"

class SimulationScene : public Kyuubi::Scene {
public:
	void draw(SDL_Renderer* renderer) override;
	void addObject(Object&) override;
	void addObject(std::vector<Object> objects) override;

	Cell& getCellAt(int index);
	void handleInput(int mouseX, int mouseY);
private:
	std::vector<Cell> cells = std::vector<Cell>();
};