#include "../../headers/organisms/cell.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <time.h>

Cell::Cell()
{

}

Cell::Cell(sf::Vector2f cellPosition)
{
    (this->form).setRadius(cellRadius);
    (this->form).setFillColor(sf::Color::Black);
    (this->form).setPosition(cellPosition);

    this->position = cellPosition;
}

void Cell::setPosition(sf::Vector2f cellPosition)
{
    (this->form).setPosition(cellPosition);
    this->position = cellPosition;
}

void Cell::setLiveColor()
{
    (this->form).setFillColor(sf::Color::Green);
}

void Cell::setDeadColor()
{
    (this->form).setFillColor(sf::Color::Black);
}

sf::CircleShape Cell::getShape()
{
    return this->form;
}

int Cell::getPositionX()
{
    return this->position.x;
}

int Cell::getStatus()
{
    return this->isAlive;
}

int Cell::getPositionY()
{
    return this->position.y;
}
