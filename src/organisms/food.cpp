#include "..\..\headers\organisms\food.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>

Food::CellFood::CellFood(sf::Vector2f foodPosition)
{
    (this->form).setRadius(5.0f);
    (this->form).setFillColor(sf::Color::Green);
    (this->form).setPosition(foodPosition);

    this->position = foodPosition;

}


sf::CircleShape Food::CellFood::getShape()
{
    return this->form;
}

