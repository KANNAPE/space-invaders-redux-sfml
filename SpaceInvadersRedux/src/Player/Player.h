#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

namespace sf
{
	class RenderWindow;
}

class Player
{
public:
							Player();

	void					Update(float _deltaTime);

	void					Render(sf::RenderWindow& window);

protected:
	sf::RectangleShape		m_sfShape;
	float					m_speed;
};