#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once

class Cell
{
private:

    sf::Vector2f position;
    sf::CircleShape form;

public:

    bool isAlive = true;

    unsigned cellFlag[9]{};

    Cell();
    Cell(sf::Vector2f foodPosition);

    static const int cellRadius = 5;

    void setPosition(sf::Vector2f cellPosition);
    void deadCell();
    void liveCell();

    int getPositionX();
    int getPositionY();

    sf::CircleShape getShape();
    sf::Color getColor();
};




