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

	virtual void handleEvent(std::optional<sf::Event> event, sf::RenderWindow& window);
	virtual void update(float delta);

	template<typename T, typename... Args>
	T* createObject(Args&&... args)
	{
		T* newObj = new T(std::forward<Args>(args)...);
		m_gameObjects.push_back(newObj);

		if constexpr (std::is_base_of_v<UIObject, T>)
			m_uiObjects.push_back(newObj);

		return newObj;
	}

	// UI callbacks
	inline UIObject* getCurrentSelection() const { return m_selection; }

	virtual void onSelectionChanged(UIObject* newSelection);
	virtual void onValidateSelection();
	virtual void onValidateBack();
	
protected:
	void drawObjects(sf::RenderWindow& window);

	std::vector<GameObjectBase*> m_gameObjects;

	std::vector<UIObject*> m_uiObjects;
	UIObject* m_selection;

	friend class Game;
};

#endif //__GAME_STATE_BASE_H__