#include "GameStateMainMenu.h"

GameStateMainMenu::GameStateMainMenu()
	: m_state(State::MainMenu)
{}

bool GameStateMainMenu::create()
{
	m_state = State::MainMenu;

	// creating objects, title and buttons

	return true;
}

void GameStateMainMenu::update(float /*delta*/)
{
	//
}
