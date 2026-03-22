#ifndef __GAME_STATE_IN_GAME_H__
#define __GAME_STATE_IN_GAME_H__

#include "GameStateBase.h"
#include "GameObject/GameObjectBase.h"

#include "SFML/Graphics/CircleShape.hpp"

struct PlayerObject : public GameObjectBase
{
	PlayerObject();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::CircleShape m_shape;
};

class GameStateInGame : public GameStateBase
{
public:
	bool create() override;

	PlayerObject* m_player{ nullptr };
};

#endif //__GAME_STATE_IN_GAME_H__