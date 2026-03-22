#ifndef __GAME_STATE_BASE_H__
#define __GAME_STATE_BASE_H__

#include "GameObject/GameObjectBase.h"
#include "GameObject/UI/UIObject.h"

#include <iostream>
#include <vector>

namespace sf
{
	class Event;
	class RenderWindow;
}

class GameStateBase
{
public:
	GameStateBase();
	virtual ~GameStateBase() = default;

	virtual bool create();
	virtual void destroy();

	template<class T>
	T* createObject()
	{
		T* newObj = new T;
		m_gameObjects.push_back(newObj);

		if (dynamic_cast<UIObject*>(newObj) != nullptr)
			m_uiObjects.push_back(newObj);

		return newObj;
	}

	virtual void handleEvent(std::optional<sf::Event> event, sf::RenderWindow& window);

	virtual void update(float /*delta*/) {}
	
protected:
	void drawObjects(sf::RenderWindow& window);

	std::vector<const GameObjectBase*> m_gameObjects;

	std::vector<UIObject*> m_uiObjects;
	UIObject* m_selection;

	friend class Game;
};

#endif //__GAME_STATE_BASE_H__