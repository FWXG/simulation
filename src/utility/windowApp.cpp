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
        if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            isGamePause = true;
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

            if(!isGamePause)
            {
                cellCycle();
                cellLife();
            }

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
        for(int i = 0; i < cellColony.size(); ++i)
        {
            if(cellColony[i].isAlive)
            {
                for(int j = 0; j < cellColony.size(); ++j)
                {
                    if(i == j) continue;
                    //For + direction
                    if(cellColony[j].isAlive)
                    {
                        if(cellColony[i].getPositionY() == cellColony[j].getPositionY())
                        {
                            if((cellColony[i].getPositionX() == (cellColony[j].getPositionX() - 10)))
                            {
                                cellColony[i].cellFlag[RIGHT_POSITION] = 1;
                            }
                            if ((cellColony[i].getPositionX() == (cellColony[j].getPositionX() + 10)))
                            {
                                cellColony[i].cellFlag[LEFT_POSITION] = 1;
                            }
                        }

                        if(cellColony[i].getPositionX() == cellColony[j].getPositionX())
                        {
                            if((cellColony[i].getPositionY() == (cellColony[j].getPositionY() - 10)))
                            {
                                cellColony[i].cellFlag[BOTTOM_POSITION] = 1;
                            }
                            if ((cellColony[i].getPositionY() == (cellColony[j].getPositionY() + 10)))
                            {
                                cellColony[i].cellFlag[TOP_POSITION] = 1;
                            }
                        }
                    // For x direction
                        if(cellColony[i].getPositionX() == (cellColony[j].getPositionX() - 10))
                        {
                            if(cellColony[i].getPositionY() == (cellColony[j].getPositionY() + 10))
                            {
                                cellColony[i].cellFlag[TOP_RIGHT_POSITION] = 1;
                            }
                            if(cellColony[i].getPositionY() == (cellColony[j].getPositionY() - 10))
                            {
                                cellColony[i].cellFlag[BOTTOM_RIGHT_POSITION] = 1;
                            }
                        }
                        if(cellColony[i].getPositionX() == (cellColony[j].getPositionX() + 10))
                        {
                            if(cellColony[i].getPositionY() == (cellColony[j].getPositionY() + 10))
                            {
                                cellColony[i].cellFlag[TOP_LEFT_POSITION] = 1;
                            }
                            if(cellColony[i].getPositionY() == (cellColony[j].getPositionY() - 10))
                            {
                                cellColony[i].cellFlag[BOTTOM_LEFT_POSITION] = 1;
                            }
                        }
                    }

                }

            }
        }

}

void Application::cellLife()
{
    for(int i = 0; i < cellColony.size(); ++i)
    {
        int sum = 0;
        for(int j = 1; j < 9; ++j){
            //std::cout << "cell number: " << i << " " << "flag number : " << j << " " << cellColony[i].cellFlag[j] << std::endl;
            sum += cellColony[i].cellFlag[j];
        }

        std::cout << "sum i:" << i << " " << sum;
        std::cout << "cell i:" << i << " " << std::boolalpha << cellColony[i].isAlive << std::endl;


        if(sum < 2 || sum > 3){
            cellColony[i].isAlive = false;
            cellColony[i].deadCell();
        }
        if(sum == 3 || sum == 2){

            if(!cellColony[i].isAlive)
                cellColony[i].liveCell();

            cellColony[i].liveCell();
        }

        for(int j = 1; j < 9; ++j){
            cellColony[i].cellFlag[j] = 0;
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





