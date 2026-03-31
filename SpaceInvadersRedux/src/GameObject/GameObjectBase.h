#ifndef __GAME_OBJECT_BASE_H__
#define __GAME_OBJECT_BASE_H__

// Graphics
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace sf
{
	class RenderWindow;
}

// Abstract
class GameObjectBase : public sf::Drawable, public sf::Transformable
{
public:
	GameObjectBase();

	inline bool isVisible() const { return m_isVisible; }
	inline void setVisible(float visible) { m_isVisible = visible;  }

	virtual void update(float /*delta*/) {}

protected:
	bool m_isVisible;
};

#endif //__GAME_OBJECT_BASE_H__