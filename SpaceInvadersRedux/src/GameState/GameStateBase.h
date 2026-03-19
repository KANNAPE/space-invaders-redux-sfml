#ifndef __GAME_STATE_BASE_H__
#define __GAME_STATE_BASE_H__

#include <vector>
#include "GameObject/GameObjectBase.h"

namespace sf
{
	class RenderWindow;
}

class GameStateBase
{
public:
	GameStateBase() = default;
	GameStateBase(const GameStateBase& /*other*/) = default;
	virtual ~GameStateBase() = default;

	GameStateBase& operator=(const GameStateBase& /*other*/) = default;

	virtual bool create() { return true; }
	virtual void destroy() {}
	virtual void update(float /*delta*/) {}
	
	virtual void drawObjects(sf::RenderWindow& window);

protected:
	std::vector<GameObjectBase*> m_gameObjects;
};

#endif //__GAME_STATE_BASE_H__