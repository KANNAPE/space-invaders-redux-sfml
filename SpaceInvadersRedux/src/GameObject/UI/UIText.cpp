#include "UIText.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

#include "SFML/System/String.hpp"

UIText::UIText()
	: UIText({ 0.f, 0.f })
{}

UIText::UIText(const sf::Vector2f& position)
	: UIObject(position)
	, m_font("C:\\Windows\\Fonts\\arial.ttf")
	, m_text(m_font, "Text")
{}

void UIText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());

	target.draw(m_text, states);
}

void UIText::setString(const sf::String& text)
{
	m_text.setString(text);
}
