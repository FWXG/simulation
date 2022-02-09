#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../organisms/cell.h"
#include <vector>
#pragma once

class Application
{
private:

    const int gridRows = 105; // Size of screen divided by 10
    const int gridCols = 168;
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


