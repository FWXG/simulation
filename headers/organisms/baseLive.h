#pragma ones
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Base
{
	class BaseLive
	{
	protected:

		sf::Vector2f m_position;
		sf::Color m_color;
		sf::CircleShape m_form; //@ why i can't use sf::Shape as Parent and reuse it in daughter class?

		virtual void setPosition(BaseLive *pObject) = 0;

	};
}