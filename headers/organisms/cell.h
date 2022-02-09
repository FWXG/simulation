#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once

class Cell
{
private:

    sf::Vector2f position;
    sf::Color color;
    sf::CircleShape form;

public:

    enum class isAlive
    {
        DEAD,
        ALIVE
    };

    unsigned cellFlag[9]{};
    //uint16_t cellFlag = 0;

    Cell();
    Cell(sf::Vector2f foodPosition);

    static const int cellRadius = 5;
    void setPosition(sf::Vector2f cellPosition);

    int getPositionX();
    int getPositionY();

    sf::CircleShape getShape();
};




