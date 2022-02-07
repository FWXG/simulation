#include "..\..\headers\utility\window.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "../../headers/organisms/food.h"
#include <random>
#include <iostream>

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

    //Random position for vectors
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(100.0f,700.0f);

    //Make 2 vectors of of CellFood class, it is position of food
    sf::Vector2f firstVector(dist(rng), dist(rng));

    //Make 2 objects of CellFood class
    Food::CellFood oneFood(firstVector);

    //Make dynamic array
    Food::CellFood *arrayOfFood = new Food::CellFood[5];
    for(int i = 0; i < 5; ++i)
    {
        arrayOfFood[i] = oneFood;
        firstVector.x -= 50.0f;
        firstVector.y -= 10.0f;
        oneFood.setPosition(firstVector);
    }


    sf::Event event;
    while (window.isOpen())
    {

            window.pollEvent(event);

            if (event.type == event.Closed)
                    window.close();

            if (event.type == event.Resized)
            {
                std::cout << "new width: "  << event.size.width  << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }

            window.clear(window_color);

            /*// I think drop is here because close event start in time check array and i have error
            for(int i = 0; i < 5; ++i){
                window.draw(arrayOfFood[i].getShape());
            }
            */
            window.display();

    }

    delete arrayOfFood;
}
