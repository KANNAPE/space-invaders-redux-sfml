#include "Game.h"

#include <iostream>

#include "GameState/GameStateMainMenu.h"

bool Game::initGame()
{
	sf::VideoMode videoMode({ DEFAULT_WINDOW_W, DEFAULT_WINDOW_H });
	m_window.create(videoMode, "Space Invaders REDUX");

	// setup here default settings, read from a file like settings.ini maybe

	GameStateMainMenu menuGameState;
	if (!menuGameState.create())
	{
		std::cerr << "There was a problem when creation the state" << std::endl;
		return false;
	}

	m_gameStates.push(menuGameState);

	return true;
}

void Game::runGame()
{
	sf::Clock clock;

	while (m_window.isOpen())
	{
		float delta = clock.restart().asSeconds();

		processInputs();

		update(delta);

		renderFrame();
	}
}

void Game::processInputs()
{
	//
}

void Game::update(float delta)
{
	if (m_gameStates.empty())
		return;

	GameStateBase& gameState = m_gameStates.top();
	
	gameState.update(delta);
}

void Game::renderFrame()
{
	GameStateBase& gameState = m_gameStates.top();

	gameState.drawObjects(m_window);
}