#include "..\..\headers\utility\window.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "../../headers/organisms/food.h"
#include <random>

// Generator of random coordinates of food
sf::Vector2f randomFoodPosition()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(100.0f,700.0f);

    sf::Vector2f foodPosition(dist(rng), dist(rng));

    return foodPosition;
}



void Window::createWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulation");

    sf::Color window_color(0, 0, 0, 255);


    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(100.0f,700.0f);

    sf::Vector2f firstVector(dist(rng), dist(rng));
    sf::Vector2f secondVector(dist(rng), dist(rng));

    Food::CellFood oneFood(firstVector);
    Food::CellFood secondFood(secondVector);


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
            window.draw(secondFood.getShape());

            window.display();

        }
    }
}
