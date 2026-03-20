#include "UIButton.h"

#include "Utils/Color.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

UIButton::UIButton()
	: UIButton({ 0.f, 0.f })
{}

UIButton::UIButton(const sf::Vector2f& position)
	: UIObject(position)
	, m_title(position)
	, m_padding({ 25.f, 15.f })
{
	//m_padding = { 0.f, 0.f };

	m_bounds.setPosition(position);
	m_bounds.setSize(m_padding);
	m_bounds.setFillColor(Utils::Color::Transparent);
	m_bounds.setOutlineColor(Utils::Color::White);
	m_bounds.setOutlineThickness(1.f);
}

void UIButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());

	target.draw(m_bounds);
	target.draw(m_title);
}

void UIButton::onSelect()
{
	m_bounds.setFillColor(Utils::Color::Black);
}

void UIButton::onUnselect()
{
	m_bounds.setFillColor(Utils::Color::Transparent);
}

void UIButton::setTitle(const sf::String& title)
{
	m_title.setString(title);

	// Resizing the bounds
	const auto& text = m_title.getText();
	auto textBounds = text.getGlobalBounds();
	
	m_title.setPosition(getPosition());
	m_title.move({ m_padding.x / 2.f, 0.f });

	m_bounds.setSize(textBounds.size + m_padding);
}
