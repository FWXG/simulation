#pragma once
#include "baseLive.h"

class Cell : public Base::BaseLive
{
public:
    Cell();
    Cell(sf::Vector2f foodPosition);
    void setPosition(sf::Vector2f cellPosition);
    sf::CircleShape getShape();

};
