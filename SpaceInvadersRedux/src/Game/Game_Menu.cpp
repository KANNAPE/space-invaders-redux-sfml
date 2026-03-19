#include "Game.h"

void Game::ProcessEvents_Menu()
{
	//
}

void Game::Update_Menu(float _deltaTime)
{

}

void Game::Render_Menu()
{
	m_sfWindow.draw(m_menu.m_menuTitle);
	for (const auto& menuButton : m_menu.m_menuButtons)
	{
		m_sfWindow.draw(menuButton.m_shape);
		m_sfWindow.draw(menuButton.m_text); // text over the shape
	}
}


// ---------------
Game::MenuState::MenuState()
	: m_menuState(Game::MenuState::State::E_Menu_PressStart)
	, m_menuTextFont("Assets\\Fonts\\arial.ttf")
	, m_menuTitle(m_menuTextFont, "Space Invaders REDUX")
{
	m_menuTitle.setPosition({ 100.f, 100.f });

	for (int buttonIdx = 0; buttonIdx < (int)ButtonType::E_COUNT; ++buttonIdx)
	{
		sf::RectangleShape shape;
		shape.setSize({ 175.f, 40.f });
		shape.setOutlineThickness(1.f);
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineColor(sf::Color::Red);
		shape.setPosition({ 100.f, 200.f + (buttonIdx * 50.f) });

		sf::Text textInButton(m_menuTextFont);

		if (buttonIdx == (int)ButtonType::E_NewGame)
			textInButton.setString("New Game");
		if (buttonIdx == (int)ButtonType::E_LoadGame)
			textInButton.setString("Load Game");
		if (buttonIdx == (int)ButtonType::E_Settings)
			textInButton.setString("Settings");
		if (buttonIdx == (int)ButtonType::E_Credits)
			textInButton.setString("Credits");
		if (buttonIdx == (int)ButtonType::E_Quit)
			textInButton.setString("Quit");

		textInButton.setPosition(shape.getPosition());

		Button button(shape, textInButton);
		m_menuButtons.push_back(button);
	}	
}

Game::MenuState::Button::Button(const sf::RectangleShape& shape, const sf::Text& text)
	: m_shape(shape)
	, m_text(text)
{}