#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <stack>

#include "GameObject/GameObjectBase.h"
#include "GameState/GameStateBase.h"

#include "SFML/Graphics/RenderWindow.hpp"

#define DEFAULT_WINDOW_W 600
#define DEFAULT_WINDOW_H 800

class Game
{
public:
	bool initGame();
	void runGame();

	void processInputs();
	void update(float delta);
	void renderFrame();

private:
	sf::RenderWindow m_window;

	std::stack<GameStateBase> m_gameStates;
};

#endif //__GAME_H__