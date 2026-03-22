#include "UIObject.h"

UIObject::UIObject()
{}

UIObject::UIObject(const sf::Vector2f& position)
	: UIObject()
{
	setPosition(position);
}

void UIObject::update(float delta)
{
	// fetching input map from the game manager

	// checking if hovered / clicked on

	// calling corresponding callbacks
}

sf::FloatRect UIObject::getBounds() const
{
	return sf::FloatRect();
}
