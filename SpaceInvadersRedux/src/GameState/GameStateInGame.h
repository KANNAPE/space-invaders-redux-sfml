#ifndef __GAME_STATE_IN_GAME_H__
#define __GAME_STATE_IN_GAME_H__

#include "GameStateBase.h"
#include "GameObject/GameObjectBase.h"

#include "SFML/Graphics/CircleShape.hpp"

namespace sf
{
	class Event;
}

class Player;
class Bullet;

class GameStateInGame : public GameStateBase
{
public:
	GameStateInGame();

	bool create() override;

	void handleEvent(std::optional<sf::Event> event, sf::RenderWindow& window) override;

	Player* m_player;

	int m_bulletIdx;
	std::vector<Bullet*> m_bulletPool;
};

#endif //__GAME_STATE_IN_GAME_H__