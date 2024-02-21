#include "SimulationScene.h"
#include "Log.h"

void SimulationScene::draw(SDL_Renderer* renderer) {
    //Conway("Checking for Draw call");
    if (cells.empty()) { return; }
    //Conway("Drawing Simulation");
    for (Cell cell : cells) {
        if (cell.Enabled) {
            SDL_SetRenderDrawColor(renderer, cell.color.r, cell.color.g, cell.color.b, cell.color.a);
        }
        else {
            SDL_SetRenderDrawColor(renderer, 0,0,0, cell.color.a);
        }

        SDL_Rect sdlrect;
        sdlrect.x = cell.PosX;
        sdlrect.y = cell.PosY;
        sdlrect.w = cell.SizeX;
        sdlrect.h = cell.SizeY;

        SDL_RenderFillRect(renderer, &sdlrect);
    }
    SDL_RenderPresent(renderer);
}

void SimulationScene::addObject(Object& object) {
    Conway("Adding single object");
    Cell* cellPtr = dynamic_cast<Cell*>(&object);

    if (cellPtr) {
        Conway("Pushing " << cellPtr);
        cells.push_back(*cellPtr);
    }
}

void SimulationScene::addObject(std::vector<Object> objects) {
    Conway("Adding object vector");
    std::vector<Cell> newCells;

    for (auto& obj : objects) {
        newCells.push_back(*dynamic_cast<Cell*>(&obj));
    }

    cells.insert(cells.end(), newCells.begin(), newCells.end());
}

Cell& SimulationScene::getCellAt(int index) {
    return cells.at(index);
}

void SimulationScene::handleInput(int mouseX, int mouseY) {
    for (Cell& cell : cells) {
        cell.checkMouseOver(mouseX, mouseY);
    }
}
