#include "Cell.h"

Cell* Cell::hoveredCell = nullptr;

void Cell::checkMouseOver(int mouseX, int mouseY) {
    if (mouseX >= PosX && mouseX <= (PosX + SizeX)) {
        if (mouseY >= PosY && mouseY <= (PosY + SizeY)) {
            Cell::hoveredCell = this;
        }
    }
}

std::string Cell::GetName() {
    return std::string();
}

long long Cell::GetID() {
    return 0;
}