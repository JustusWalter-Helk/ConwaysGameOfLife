#pragma once
#include "Util/Color.h"

#include "Log.h"

#include "Core/Object.h"

#include "SDL2/SDL.h"

using namespace Kyuubi;

class Cell : public Object{
public:
	static Cell* hoveredCell;

	int row;
	int column;
	int aliveNeighbours = 0;

	Cell(float posX = 0.0f, float posY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, int row = 0, int column = 0, const Color& col = Color())
		: PosX(posX), PosY(posY), SizeX(sizeX), SizeY(sizeY), color(col), row(row), column(column) {
	}

	void checkMouseOver(int mouseX, int mouseY);
	std::string GetName() override;
	long long GetID() override;

	bool Enabled = false;

	float PosX, PosY, SizeX, SizeY;
	Color color;
private:

};