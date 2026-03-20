#ifndef __GAME_STATE_MENU_H__
#define __GAME_STATE_MENU_H__

#include "GameStateBase.h"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

struct TextWidget : public GameObjectBase
{
	TextWidget()
		: m_font("C:\\Windows\\Fonts\\arial.ttf")
		, m_text(m_font, "Text")
	{}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		states.transform.translate(getPosition());

		target.draw(m_text, states);
	}

	sf::Font m_font;
	sf::Text m_text;
};

struct ButtonWidget : public GameObjectBase
{
	ButtonWidget()
		: m_bounds({ 125.f, 75.f })
	{
		m_bounds.setFillColor(sf::Color::Transparent);
		m_bounds.setOutlineColor(sf::Color::Red);
		m_bounds.setOutlineThickness(1.f);
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		states.transform.translate(getPosition());

		target.draw(m_bounds);
		target.draw(m_title);
	}

	sf::RectangleShape m_bounds;
	TextWidget m_title;
};

class GameStateMainMenu : public GameStateBase
{
public:
	GameStateMainMenu();

	bool create() override;
	void update(float delta) override;

protected:
	enum class State
	{
		MainMenu,
		NewGame,
		LoadGame,
		Settings_Display,
		Settings_Audio,
		Credits,
		Quit,

		COUNT
	};

	enum class ButtonType
	{
		NewGame,
		LoadGame,
		Settings,
		Credits,
		QuitGame,

		COUNT
	};

	State m_state;

	// UI
	TextWidget m_menuTitle;
	std::vector<ButtonWidget> m_menuButtons;
};

#endif //__GAME_STATE_MENU_H__