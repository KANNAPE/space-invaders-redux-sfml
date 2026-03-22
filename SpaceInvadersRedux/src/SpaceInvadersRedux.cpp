#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game/Game.h"

int main()
{
	Game game;

	if (!game.initGame())
	{
		std::cerr << "There was an issue when initializing the game manager!" << std::endl;
		return 1;
	}

	game.runGame();

	game.deinitGame();

	return 0;
}