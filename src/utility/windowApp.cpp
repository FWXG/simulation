#include "../../headers/utility/windowApp.h"
#include "../../headers/organisms/cell.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <random>
#include <iostream>

// Generator of random coordinates of food
sf::Vector2f randomCellPosition()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(100.0f,700.0f);

    sf::Vector2f cellPosition(dist(rng), dist(rng));

    return cellPosition;
}

Application::Application() : window(sf::VideoMode(800, 600), "Test")
{

}

void Application::handleEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::Resized)
        {
            std::cout << "new width: "  << event.size.width  << std::endl;
            std::cout << "new height: " << event.size.height << std::endl;
        }
    }
}

void Application::createWindow()
{

    sf::Color window_color(0, 0, 0, 255);

    //Random position for vectors
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(100.0f,700.0f);

    //Make 2 vectors of of CellFood class, it is position of food
    sf::Vector2f firstVector(dist(rng), dist(rng));

    //Make 2 objects of CellFood class
    Cell oneCell(firstVector);

    //Make dynamic array
    /*Cell *arrayOfCell = new Cell[5];
    for(int i = 0; i < 5; ++i)
    {
        arrayOfCell[i] = oneCell;
        firstVector.x -= 50.0f;
        firstVector.y -= 10.0f;
        oneCell.setPosition(firstVector);
    }*/


    while (window.isOpen())
    {

            handleEvents();

            window.clear(window_color);

            /*for(int i = 0; i < 5; ++i){
                window.draw(arrayOfCell[i].getShape());
            }*/

            window.display();

    }

    //delete arrayOfCell;
}
