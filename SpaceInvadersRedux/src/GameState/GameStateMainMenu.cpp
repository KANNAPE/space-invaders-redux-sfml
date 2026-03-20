#include "GameStateMainMenu.h"

#include "SFML/Graphics/Font.hpp"

GameStateMainMenu::GameStateMainMenu()
	: m_state(State::MainMenu)
{}

bool GameStateMainMenu::create()
{
	if (!GameStateBase::create())
		return false;

	m_state = State::MainMenu;

	m_menuTitle = new UIText;

	m_menuTitle->setString("Space Invaders REDUX");
	m_menuTitle->setPosition({ 200.f, 100.f });

	m_gameObjects.push_back(m_menuTitle);

	for (int buttonIdx = 0; buttonIdx < static_cast<int>(ButtonType::COUNT); ++buttonIdx)
	{
		UIButton* button = new UIButton({ 200.f, 150.f + 50.f * buttonIdx });
		
		switch (static_cast<ButtonType>(buttonIdx))
		{
		case ButtonType::NewGame:
			button->setTitle("New Game");
			break;
		case ButtonType::LoadGame:
			button->setTitle("Load Game");
			break;
		case ButtonType::Settings:
			button->setTitle("Settings");
			break;
		case ButtonType::Credits:
			button->setTitle("Credits");
			break;
		case ButtonType::Quit:
			button->setTitle("Quit");
			break;
		default:
		{}
		}
		
		m_menuButtons.push_back(button);
		m_gameObjects.push_back(button);
	}

	return true;
}

void GameStateMainMenu::update(float /*delta*/)
{
	//
}
