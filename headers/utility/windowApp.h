#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#pragma ones

class Application
{
private:

    sf::RenderWindow window;

public:

    Application();

    void createWindow();
    void handleEvents();
};


