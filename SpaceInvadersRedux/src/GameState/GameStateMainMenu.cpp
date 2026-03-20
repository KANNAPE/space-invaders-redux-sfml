#include "GameStateMainMenu.h"

#include "SFML/Graphics/Font.hpp"

GameStateMainMenu::GameStateMainMenu()
	: m_state(State::MainMenu)
{}

bool GameStateMainMenu::create()
{
	m_state = State::MainMenu;

	m_menuTitle.m_text.setString("Space Invaders REDUX");
	m_menuTitle.setPosition({ 200.f, 100.f });

	m_gameObjects.push_back(&m_menuTitle);

	return true;
}

void GameStateMainMenu::update(float /*delta*/)
{
	//
}
