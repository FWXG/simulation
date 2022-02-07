#include "..\..\headers\utility\window.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "../../headers/organisms/food.h"

void Window::createWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulation");

    sf::Color window_color(0, 0, 0, 255);

    sf::Vector2f foodPosition(15.0f,45.0f);
    sf::CircleShape circle;

    Food::CellFood oneFood(foodPosition, sf::Color::Yellow, circle);

    sf::CircleShape tmp(10.0f);
    tmp.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {

        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(window_color);

            window.draw(oneFood.getShape());

            window.display();

        }
    }
}
