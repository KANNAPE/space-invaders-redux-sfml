#ifndef __UI_BUTTON_H__
#define __UI_BUTTON_H__

#include "UIObject.h"
#include "UIText.h"

#include "SFML/Graphics/RectangleShape.hpp"

class UIButton : public UIObject
{
public:
	UIButton();
	
	sf::FloatRect getBounds() const override;

	void onSelect() override;
	void onUnselect() override;
	void onValidate() override;

	void setTitle(const sf::String& title);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	UIText m_title;

	sf::RectangleShape m_bounds;
	sf::Vector2f m_padding;
};

#endif //__UI_BUTTON_H__