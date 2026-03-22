#include "UIText.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

#include "SFML/System/String.hpp"

UIText::UIText()
	: m_font(DEFAULT_FONT_FILE)
	, m_text(m_font, "Text")
{}

sf::FloatRect UIText::getBounds() const
{
	return m_text.getGlobalBounds();
}

void UIText::setString(const sf::String& text)
{
	m_text.setString(text);
}

void UIText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());

	target.draw(m_text, states);
}
