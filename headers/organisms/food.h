#pragma ones
#include "baseLive.h"

namespace Food
{
	class CellFood : public Base::BaseLive
	{
	public:

		CellFood(sf::Vector2f foodPosition);
		sf::CircleShape getShape();

	};

}
