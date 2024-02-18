#pragma once

#include "Color.h"

namespace Kyuubi {
	class Rectangle
	{
	public:
		float PosX, PosY, SizeX, SizeY;
		Color color;

		Rectangle(float posX = 0.0f, float posY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, const Color& col = Color())
			: PosX(posX), PosY(posY), SizeX(sizeX), SizeY(sizeY), color(col) {}
	};
}

