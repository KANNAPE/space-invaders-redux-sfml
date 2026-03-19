#include "Game.h"

bool Game::initGame()
{
	sf::VideoMode videoMode({ DEFAULT_WINDOW_W, DEFAULT_WINDOW_H });
	m_window.create(videoMode, "Space Invaders REDUX");



	// setup here default settings, read from a file like settings.ini maybe

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