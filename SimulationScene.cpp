#include "SimulationScene.h"
#include "Log.h"

void SimulationScene::draw(SDL_Renderer* renderer) {
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

void SimulationScene::doSimulationStep() {
    for (Cell& cell : cells) {
        int row = cell.row;
        int column = cell.column;

        Cell& left = getCellAtPosition(row - 1, column);
        Cell& up = getCellAtPosition(row, column + 1);
        Cell& right = getCellAtPosition(row + 1, column);
        Cell& down = getCellAtPosition(row, column - 1);

        Cell& leftUp = getCellAtPosition(row - 1, column + 1);
        Cell& leftDown = getCellAtPosition(row - 1, column - 1);
        Cell& rightUp = getCellAtPosition(row + 1, column + 1);
        Cell& rightDown = getCellAtPosition(row + 1, column - 1);

        cell.aliveNeighbours = 0 + left.Enabled + up.Enabled + right.Enabled + down.Enabled + leftUp.Enabled + leftDown.Enabled + rightUp.Enabled + rightDown.Enabled;
    }
    for (Cell& cell : cells) {
        int aliveCounter = cell.aliveNeighbours;

        if (cell.Enabled && aliveCounter < 2) cell.Enabled = false;
        if (cell.Enabled && (aliveCounter == 2 || aliveCounter == 3)) cell.Enabled = true;
        if (cell.Enabled && aliveCounter > 3) cell.Enabled = false;
        if (cell.Enabled == false && aliveCounter == 3) cell.Enabled = true;
    }
}

Cell& SimulationScene::getCellAtPosition(int row, int column) {
    for (Cell& cell : cells) {
        if (cell.row == row && cell.column == column) {
            return cell;
        }
    }

    static Cell defaultCell;
    return defaultCell;
}
