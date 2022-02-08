#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../organisms/cell.h"
#include <vector>
#pragma once

class Application
{
private:

    const int gridRows = 30;
    const int gridCols = 30;
    sf::Mouse mouse;
    sf::RenderWindow window;
    std::vector<Cell> cellColony;

    void createArrayOfCells();
    void cellCycle();
    void handleEvents();
    void drawGrid();

public:

    Application();
    void createWindow();

};


