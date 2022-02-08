#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../organisms/cell.h"
#include <vector>
#pragma ones

class Application
{
private:

    sf::Mouse mouse;
    sf::RenderWindow window;
    std::vector<Cell> cellColony;
    void createArrayOfCells();

public:

    Application();

    void createWindow();
    void handleEvents();
};


