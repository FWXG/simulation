#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../organisms/cell.h"
#include <vector>
#pragma once

class Application
{
private:

    bool isGridOpen;

    const int gridRows = sf::VideoMode::getDesktopMode().height / (Cell::cellRadius * 2); // Size of screen divided by 10
    const int gridCols = sf::VideoMode::getDesktopMode().width / (Cell::cellRadius * 2);
    int cellFlag;

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


