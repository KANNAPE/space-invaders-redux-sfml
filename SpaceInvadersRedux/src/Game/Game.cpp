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

	m_states.push_back(State::E_Menu);

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

	switch (m_states.back())
	{
	case State::E_Menu:
		ProcessEvents_Menu();
		break;
	case State::E_Settings:
		//ProcessEvents_Settings();
		break;
	case State::E_Game:
		///ProcessEvents_Game();
		break;
	case State::E_Pause:
		//ProcessEvents_Pause();
		break;
	default:
	{}
	}
}

void Game::Update(float _deltaTime)
{
	switch (m_states.back())
	{
	case State::E_Menu:
		Update_Menu(_deltaTime);
		break;
	case State::E_Settings:
		//Update_Settings(_deltaTime);
		break;
	case State::E_Game:
		//Update_Game(_deltaTime);
		break;
	case State::E_Pause:
		//Update_Pause(_deltaTime);
		break;
	default:
	{}
	}
}

void Game::Render()
{
	m_sfWindow.clear();

	switch (m_states.back())
	{
	case State::E_Menu:
		Render_Menu();
		break;
	case State::E_Settings:
		//Render_Settings();
		break;
	case State::E_Game:
		//Render_Game();
		break;
	case State::E_Pause:
		//Render_Pause();
		break;
	default:
	{}
	}

	m_sfWindow.display();
}
