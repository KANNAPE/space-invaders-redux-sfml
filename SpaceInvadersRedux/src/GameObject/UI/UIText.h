#ifndef __UI_TEXT_H__
#define __UI_TEXT_H__

#include "UIObject.h"

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

namespace sf
{
	class RenderTarget;
	class String;

	struct RenderStates;
}

class UIText : public UIObject
{
public:
	UIText();
	UIText(const sf::Vector2f& position);

	inline const sf::Font& getFont() const { return m_font; }
	inline const sf::Text& getText() const { return m_text; }

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setString(const sf::String& text);

protected:
	sf::Font m_font;
	sf::Text m_text;
};

#endif //__UI_TEXT_H__