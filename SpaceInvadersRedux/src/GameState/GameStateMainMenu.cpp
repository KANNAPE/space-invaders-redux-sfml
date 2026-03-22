#include "GameStateMainMenu.h"

#include "Game/Game.h"

// Graphics
#include "SFML/Graphics/Font.hpp"

GameStateMainMenu::GameStateMainMenu()
	: m_state(State::MainMenu)
	, m_menuTitle(nullptr)
{}

bool GameStateMainMenu::create()
{
	if (!GameStateBase::create())
		return false;

	m_state = State::MainMenu;

	m_menuTitle = createObject<UIText>();

	m_menuTitle->setString("Space Invaders REDUX");
	m_menuTitle->setPosition({ 200.f, 100.f });

	for (int buttonIdx = 0; buttonIdx < static_cast<int>(ButtonType::COUNT); ++buttonIdx)
	{
		UIButton* button = createObject<UIButton>();
		button->setPosition({ 200.f, 150.f + 50.f * buttonIdx });		
		
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
	}

	return true;
}

void GameStateMainMenu::update(float /*delta*/)
{
	//
}

void GameStateMainMenu::onValidateSelection()
{
	GameStateBase::onValidateSelection();

	UIObject* selection = getCurrentSelection();
	if (selection == nullptr)
		return;

	if (selection == m_menuButtons[(int)ButtonType::NewGame])
		g_GameManager->pushGameState(GameStateID::GS_Game);
}
