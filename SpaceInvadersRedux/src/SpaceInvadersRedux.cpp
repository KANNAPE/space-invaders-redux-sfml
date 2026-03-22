#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game/Game.h"

int main()
{
	if (!g_GameManager->initGame())
	{
		std::cerr << "There was an issue when initializing the game manager!" << std::endl;
		return 1;
	}

	g_GameManager->runGame();

	g_GameManager->deinitGame();

	return 0;
}