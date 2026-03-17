#include "Game.h"

// System
#include <SFML/System/Clock.hpp>
// Window
#include <SFML/Window/VideoMode.hpp>

Game::Game()
	: m_sfWindow(sf::VideoMode({ 800, 600 }), "Space Invaders REDUX")
{}

void Game::RunGame()
{
	sf::Clock clock;

	while (m_sfWindow.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		ProcessEvents();

		Update(deltaTime);

		Render();
	}
}

void Game::ProcessEvents()
{
	while (const std::optional event = m_sfWindow.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			m_sfWindow.close();
		}
	}
}

void Game::Update(float _deltaTime)
{
	m_player.Update(_deltaTime);
}

void Game::Render()
{
	m_sfWindow.clear();

	m_player.Render(m_sfWindow);

	m_sfWindow.display();
}
