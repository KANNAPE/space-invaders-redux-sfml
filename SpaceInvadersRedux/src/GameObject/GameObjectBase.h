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

class GameObjectBase : public sf::Drawable, public sf::Transformable
{
public:
	GameObjectBase() = default;
	GameObjectBase(const GameObjectBase& /*other*/) = default;
	virtual ~GameObjectBase() = default;

	GameObjectBase& operator=(const GameObjectBase& /*other*/) = default;

	virtual void update(float /*delta*/) {}

	// sf::Drawable implementation
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) = 0;

protected:
	//
};

#endif //__GAME_OBJECT_BASE_H__