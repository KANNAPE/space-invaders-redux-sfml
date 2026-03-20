#include "Game.h"

#include <iostream>

#include "Utils/Color.h"

#include "GameState/GameStateMainMenu.h"
#include "GameState/GameStateInGame.h"

Game::Game()
	: m_defaultGameStateClass(GameStateClass::GS_MainMenu)
{}

bool Game::initGame()
{
	sf::VideoMode videoMode({ DEFAULT_WINDOW_W, DEFAULT_WINDOW_H });
	m_window.create(videoMode, "Space Invaders REDUX");

	// setup here default settings, read from a file like settings.ini maybe

	m_gameStates.resize(GameStateClass::GS_TOTAL);

	m_gameStates[GameStateClass::GS_MainMenu] = new GameStateMainMenu();
	m_gameStates[GameStateClass::GS_Game] = new GameStateInGame();
	for (auto* gameState : m_gameStates)
	{
		if (!gameState->create())
		{
			std::cerr << "There was an issue when creating the game state!" << std::endl;
			return false;
		}
	}

	GameStateBase* defaultGameState = m_gameStates[m_defaultGameStateClass];
	m_gameStateStack.push(defaultGameState);

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
	while (const std::optional event = m_window.pollEvent())
	{
		// closing event
		if (event->is<sf::Event::Closed>())
			m_window.close();

		// mapping events
	}
}

void Game::update(float delta)
{
	if (m_gameStates.empty())
		return;

	GameStateBase* gameState = m_gameStateStack.top();
	
	gameState->update(delta);
}

void Game::renderFrame()
{
	GameStateBase* gameState = m_gameStateStack.top();

	m_window.clear(Utils::Color::Grey);
	gameState->drawObjects(m_window);
	m_window.display();
}