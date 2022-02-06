#include "..\..\headers\utility\window.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

void Window::createWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulation");

    while (window.isOpen())
    {

        sf::Color window_color(0, 0, 0, 255);

        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(window_color);

            //window.draw(circle);

            window.display();

        }
    }
}
