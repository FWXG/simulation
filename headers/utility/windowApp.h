#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../organisms/cell.h"
#include <vector>
#pragma once

class Application
{
private:

    enum directionFlag
    {
        TOP_POSITION,
        BOTTOM_POSITION,
        RIGHT_POSITION,
        LEFT_POSITION,
        TOP_RIGHT_POSITION,
        TOP_LEFT_POSITION,
        BOTTOM_RIGHT_POSITION,
        BOTTOM_LEFT_POSITION
    };

    bool isGridOpen = false;
    bool isGamePause = true;

    const int gridRows = sf::VideoMode::getDesktopMode().height / (Cell::cellRadius * 2); // Size of screen divided by 10
    const int gridCols = sf::VideoMode::getDesktopMode().width / (Cell::cellRadius * 2);

    sf::Mouse mouse;
    sf::RenderWindow window;

    std::vector<Cell> cellColony;

    void createArrayOfCells();
    void cellCycle();
    void handleEvents();
    void drawGrid();
    void cellLife();

public:

    Application();
    void createWindow();

};


