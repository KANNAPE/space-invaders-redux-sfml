#ifndef __BULLET_H__
#define __BULLET_H__

#include "GameObject/GameObjectBase.h"

#include "SFML/Graphics/RectangleShape.hpp"

class Bullet : public GameObjectBase
{
public:
	Bullet();

	void update(float delta) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void shoot();

protected:
	sf::RectangleShape m_shape;

	// gameplay
	bool m_active;
	float m_speed;
	float m_lifeTimer;
};

#endif //__BULLET_H__