#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once

class Cell
{
private:

    sf::Vector2f position;
    sf::CircleShape form;

public:

    bool isAlive = false;

    Cell();
    Cell(sf::Vector2f cellPosition);

    static const int cellRadius = 5;

    void setPosition(sf::Vector2f cellPosition);
    void setLiveColor();
    void setDeadColor();

    int getStatus();

    int getPositionX();
    int getPositionY();

    sf::CircleShape getShape();
};




