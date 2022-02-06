#include "..\..\headers\utility\window.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

void Window::createWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulation");

    sf::CircleShape circle;
    sf::Color circle_color(45,89,56,255);
    sf::Vector2f circle_position(0.0, 0.0);

    circle.setRadius(10.0f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(circle_position);

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

            window.draw(circle);

            window.display();

        }
    }
}
