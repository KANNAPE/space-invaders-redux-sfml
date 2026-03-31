#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameObject/GameObjectBase.h"

#include "SFML/Graphics/CircleShape.hpp"

namespace sf
{
	class Event;
}

class Player : public GameObjectBase
{
public:
	Player();

	void update(float delta) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::CircleShape m_shape;

	// gameplay
	float m_speed;
	float m_direction;
};

#endif //__PLAYER_H__