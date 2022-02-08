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
    (this->form).setRadius(5.0f);
    (this->form).setFillColor(sf::Color::Green);
    (this->form).setPosition(cellPosition);

    this->position = cellPosition;

}

void Cell::setPosition(sf::Vector2f cellPosition)
{
    (this->form).setPosition(cellPosition);
    this->position = cellPosition;
}

sf::CircleShape Cell::getShape()
{
    return this->form;
}

void Cell::getPosition()
{
    std::cout << "x: " << this->position.x << "y: " << this->position.y << std::endl;
}

