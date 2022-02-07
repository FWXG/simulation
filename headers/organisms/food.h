#pragma ones
#include "baseLive.h"

namespace Food
{
	class CellFood : public Base::BaseLive
	{
	public:

		CellFood(sf::Vector2f food_position, sf::Color food_color, sf::CircleShape food_shape);
		sf::CircleShape getShape();

	};

}
