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
        if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) // All mouse buttons works
            createArrayOfCells();
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

    }
}

void Application::createArrayOfCells()
{
    sf::Vector2f cellPosition;
    cellPosition.x = mouse.getPosition().x  - mouse.getPosition().x % 10;
    cellPosition.y = mouse.getPosition().y  - mouse.getPosition().y % 10;
    Cell oneCell(cellPosition); // Creation Cell
    oneCell.setPosition(cellPosition);
    cellColony.push_back(oneCell);
}

void Application::createWindow()
{
    sf::Color window_color(0, 0, 0, 255);

    while (window.isOpen()) // "Runtime" start here
    {

            window.clear(window_color);

            //createArrayOfCells(); // put cells from mouse
            handleEvents();

            cellCycle();

            for(int i = 0; i < cellColony.size(); ++i){
                window.draw(cellColony[i].getShape()); // draw shape one cell
                //cellColony[i].getPosition(); //cout cell position
            }

            //std::cout << "x: " << mouse.getPosition().x << " y : " << mouse.getPosition().y << std::endl;

            drawGrid();

            window.display();
    }

}

// Life cell cycle
void Application::cellCycle()
{

    if(!isGamePause)
    {
        for(int i = 0; i < cellColony.size(); ++i)
        {
            int f = 1;
            //std::cout << cellColony[i].getPositionX() << std::endl;
            for(int j = i + 1; j < cellColony.size(); ++j)
            {
                if(cellColony[i].getPositionY() == cellColony[j].getPositionY())
                {
                    if((cellColony[i].getPositionX() == (cellColony[j].getPositionX() - 10)
                            || (cellColony[i].getPositionX() == (cellColony[j].getPositionX() + 10))))
                    {
                        //std::cout << "close X" << std::endl;
                        if(!cellColony[i].cellFlag[f]){
                            ++cellColony[i].cellFlag[f];
                            ++f;
                        }
                    }
                }

                if(cellColony[i].getPositionX() == cellColony[j].getPositionX())
                {
                    if((cellColony[i].getPositionY() == (cellColony[j].getPositionY() - 10)
                            || (cellColony[i].getPositionY() == (cellColony[j].getPositionY() + 10))))
                    {
                        //std::cout << "close Y" << std::endl;
                        if(!cellColony[i].cellFlag[f]){
                            ++cellColony[i].cellFlag[f];
                            ++f;
                        }
                    }
                }

            }

            std::cout << cellColony[i].cellFlag[f] << std::endl;

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

            for(int i = 0; i < gridRows - 1; ++i)
            {
                int r = i + 1;
                float rowY = rowG * r;
                grid[i * 2].position = {0, rowY};
                grid[i * 2 + 1].position = {size.x, rowY};
            }

            for(int i = gridRows - 1; i < numLines; ++i)
            {
                int c = i - gridRows + 2;
                float colX = colG * c;
                grid[i * 2].position = {colX, 0};
                grid[i * 2 + 1].position = {colX, size.y};
            }

            window.draw(grid);
        }

}





