#ifndef __GAME_H__
#define __GAME_H__

#include "GameObject/GameObjectBase.h"
#include "GameState/GameStateBase.h"

#include "SFML/Graphics/RenderWindow.hpp"

#include <vector>
#include <stack>

#define DEFAULT_WINDOW_W 800
#define DEFAULT_WINDOW_H 600

enum class GameStateID
{
	GS_MainMenu,
	GS_Game,

	GS_TOTAL
};

class Game
{
public:
	Game();

	bool initGame();
	void runGame();
	void deinitGame();

	void processInputs();
	void update(float delta);
	void renderFrame();

	void pushGameState(GameStateID gameStateClass);

private:
	sf::RenderWindow m_window;

	std::vector<GameStateBase*> m_gameStates;
	std::stack<GameStateBase*> m_gameStateStack;

	GameStateID m_defaultGameStateClass;
};
extern Game* g_GameManager;

#endif //__GAME_H__