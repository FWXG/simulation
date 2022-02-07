#pragma ones
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Base
{
	class BaseLive
	{
	protected:

		sf::Vector2f position;
		sf::Color color;
		sf::CircleShape form;

		//virtual void setPosition(BaseLive *pObject) = 0;

	};
}
