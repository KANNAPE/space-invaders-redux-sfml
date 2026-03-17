#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Player.h"

class Game
{
public:
						Game();

	void				RunGame();

protected:
	void				ProcessEvents();
	void				Update(float _deltaTime);
	void				Render();


	sf::RenderWindow	m_sfWindow;

	Player				m_player;
};