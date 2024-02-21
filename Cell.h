#pragma once
#include "Util/Color.h"

#include "Log.h"

#include "Core/Object.h"

#include "SDL2/SDL.h"

using namespace Kyuubi;

class Cell : public Object{
public:
	static Cell* hoveredCell;

	Cell(float posX = 0.0f, float posY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, const Color& col = Color())
		: PosX(posX), PosY(posY), SizeX(sizeX), SizeY(sizeY), color(col) {
	}

	void checkMouseOver(int mouseX, int mouseY);
	std::string GetName() override;
	long long GetID() override;

	bool Enabled = false;

	float PosX, PosY, SizeX, SizeY;
	Color color;
private:

};