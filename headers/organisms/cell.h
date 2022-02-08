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

    Cell();
    Cell(sf::Vector2f foodPosition);
    void setPosition(sf::Vector2f cellPosition);
    void getPosition();
    sf::CircleShape getShape();
};




