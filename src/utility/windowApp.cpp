#include "../../headers/utility/windowApp.h"
#include "../../headers/organisms/cell.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <random>
#include <iostream>

Application::Application() : window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                                   sf::VideoMode::getDesktopMode().height, 32), "Live Simulation", sf::Style::Fullscreen)
{

}

void Application::handleEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::Resized)
        {
            std::cout << "new width: "  << event.size.width  << std::endl;
            std::cout << "new height: " << event.size.height << std::endl;
        }
        if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            rebirthOfCell();
        }
        if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            std::cout << "grid open";
            isGridOpen = true;
        }
        if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            isGridOpen = false;
        }
        if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            isGamePause = false;
        }
        if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            isGamePause = true;
        }
    }
}


void Application::createWindow()
{
    sf::Color window_color(0, 0, 0, 255);
    createPoleOfCells();
    while (window.isOpen()) // "Runtime" start here
    {

            window.clear(window_color);
            handleEvents();
            //std::cout << "x: " << mouse.getPosition().x << " y : " << mouse.getPosition().y << std::endl;

            for(unsigned i = 0; i < gridRows; ++i)
            {
                for(unsigned j = 0; j < gridCols; ++j)
                {
                    window.draw(cellColony[i][j].getShape());
                }
            }

            drawGrid();

            window.display();
    }

    //Delete memory
    for(int i = 0; i < gridRows; ++i)
        delete[] cellColony[i];

    delete[] cellColony;
    //////////////////////////////////////
}

void Application::createPoleOfCells()
{
    sf::Vector2f cellposition(0, 0);
    Cell oneCell(cellposition);

    //Dynamic memory
    cellColony = new Cell*[gridRows];
    for(int i = 0; i < gridRows; ++i)
        cellColony[i] = new Cell[gridCols];
    ////////////////////////////////////

    for (unsigned i = 0; i < gridRows; i++)
    {
        for (unsigned j = 0; j < gridCols; j++)
        {
            cellColony[i][j] = oneCell;
            cellposition.x += (oneCell.cellRadius * 2);
            oneCell.setPosition(cellposition);
        }
        cellposition.y += (oneCell.cellRadius * 2);
        cellposition.x = 0;
        //std::cout << cellposition.y << std::endl;
    }
}

void Application::rebirthOfCell()
{
    int aproxMouseX = mouse.getPosition().x - (mouse.getPosition().x % 10);
    int aproxMouseY = mouse.getPosition().y - (mouse.getPosition().y % 10);

    for(unsigned i = 0; i < gridRows; ++i)
    {
        for(unsigned j = 0; j < gridCols; ++j)
        {
            if((aproxMouseX == cellColony[i][j].getPositionX()) && (aproxMouseY == cellColony[i][j].getPositionY()))
            {
                cellColony[i][j].isAlive = true;
                cellColony[i][j].setColor();
                window.draw(cellColony[i][j].getShape());
            }
        }
    }
}

void Application::drawGrid()
{
        if(isGridOpen)
        {
             int numLines = gridCols + gridRows - 2; //Minus two start pixels
            sf::VertexArray grid(sf::Lines, 2*numLines); // Make vertex array of line primitives
            window.setView(window.getDefaultView());
            auto size = window.getView().getSize();// Get size of window
            float rowG = size.y / gridRows;
            float colG = size.x / gridCols;

            for(unsigned i = 0; i < gridRows - 1; ++i)
            {
                int r = i + 1;
                float rowY = rowG * r;
                grid[i * 2].position = {0, rowY};
                grid[i * 2 + 1].position = {size.x, rowY};
            }

            for(unsigned i = gridRows - 1; i < numLines; ++i)
            {
                int c = i - gridRows + 2;
                float colX = colG * c;
                grid[i * 2].position = {colX, 0};
                grid[i * 2 + 1].position = {colX, size.y};
            }

            window.draw(grid);
        }

}





