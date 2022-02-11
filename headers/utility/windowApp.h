#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../organisms/cell.h"
#include <vector>
#pragma once

class Application
{
private:

    bool isGridOpen = false;
    bool isGamePause = true;

    const unsigned gridRows = 600 / (Cell::cellRadius * 2); // Size of screen divided by 10
    const unsigned gridCols = 800 / (Cell::cellRadius * 2);

    sf::Mouse mouse;
    sf::RenderWindow window;

    Cell **cellColony;

    void handleEvents();
    void drawGrid();
    void createPoleOfCells();
    void rebirthOfCell();
    void mainCellCycle();

public:

    Application();
    void createWindow();

};


