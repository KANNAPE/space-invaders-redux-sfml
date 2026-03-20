#ifndef __GAME_STATE_BASE_H__
#define __GAME_STATE_BASE_H__

#include "GameObject/GameObjectBase.h"
#include <vector>

namespace sf
{
	class RenderWindow;
}

class GameStateBase
{
public:
	virtual ~GameStateBase() = default;

	virtual bool create() { return true; }
	virtual void destroy() {}
	virtual void update(float /*delta*/) {}
	
	virtual void drawObjects(sf::RenderWindow& window);

protected:
	std::vector<const GameObjectBase*> m_gameObjects;
};

#endif //__GAME_STATE_BASE_H__