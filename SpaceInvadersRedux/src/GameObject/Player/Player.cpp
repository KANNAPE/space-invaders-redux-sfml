#include "Player.h"

#include "Utils/Color.h"

#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

Player::Player()
	: m_speed(180.f)
	, m_direction(0.f)
{
	m_shape = sf::CircleShape(40.f, 3);
	m_shape.setFillColor(Utils::Color::Green);
}

void Player::update(float delta)
{
	sf::Vector2f velocity{ 0.f, 0.f };

	m_direction = 0.f;

	// Left direction
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		m_direction -= 1.f;
	}
	// Right direction
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		m_direction += 1.f;
	}

	velocity.x = m_direction * m_speed * delta;

	move(velocity);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	float playerRadius = m_shape.getRadius();
	states.transform.translate({ -playerRadius, -playerRadius });

	target.draw(m_shape, states);
}

