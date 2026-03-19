#include "Player.h"

// Graphics
#include <SFML/Graphics/RenderWindow.hpp>
// Window
#include <SFML/Window/Keyboard.hpp>


Player::Player()
{
	m_sfShape.setSize({ 50.f, 50.f });
	m_sfShape.setFillColor(sf::Color::Green);
	m_sfShape.setPosition({ 375.f, 275.f });

	m_speed = 175.f;
}

void Player::Update(float _deltaTime)
{
	sf::Vector2f direction;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		direction.y -= 1.0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		direction.y += 1.0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		direction.x -= 1.0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		direction.x += 1.0;
	}

	if (direction.x != 0.f || direction.y != 0.f)
		direction = direction.normalized();

	m_sfShape.move(direction * m_speed * _deltaTime);
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sfShape);
}