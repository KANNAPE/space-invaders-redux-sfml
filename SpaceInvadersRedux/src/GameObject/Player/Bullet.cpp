#include "Bullet.h"

#include "Utils/Color.h"

#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#define BULLET_LIFE_TIMER_SECONDS 10.f

Bullet::Bullet()
	: m_active(false)
	, m_speed(-400.f)
	, m_lifeTimer(0.f)
{
	m_shape = sf::RectangleShape({ 2.f, 25.f });
	m_shape.setFillColor(Utils::Color::White);
}

void Bullet::update(float delta)
{
	GameObjectBase::update(delta);

	if (m_active == false)
		return;

	// movement
	sf::Vector2f velocity{ 0.f, 0.f };
	velocity.y = m_speed * delta;
	move(velocity);

	// timer
	m_lifeTimer += delta;
	if (m_lifeTimer >= BULLET_LIFE_TIMER_SECONDS)
		m_active = false;
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_shape, states);
}

void Bullet::shoot()
{
	m_active = true;
	m_lifeTimer = 0.f;
}
