#include "..\..\headers\organisms\food.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Food::CellFood::CellFood(sf::Vector2f food_position, sf::Color food_color, sf::CircleShape food_shape)
{
    this->form = food_shape;

    (this->form).setRadius(20.0f);
    (this->form).setFillColor(food_color);
    (this->form).setPosition(food_position);
}


sf::CircleShape Food::CellFood::getShape()
{
    return this->form;
}
