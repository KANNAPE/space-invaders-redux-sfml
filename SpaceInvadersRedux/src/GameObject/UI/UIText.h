#ifndef __UI_TEXT_H__
#define __UI_TEXT_H__

#include "UIObject.h"

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

#define DEFAULT_FONT_FILE "C:\\Windows\\Fonts\\arial.ttf"

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

	inline const sf::Font& getFont() const { return m_font; }
	inline const sf::Text& getText() const { return m_text; }

	sf::FloatRect getBounds() const override;

	void setString(const sf::String& text);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Font m_font;
	sf::Text m_text;
};

#endif //__UI_TEXT_H__