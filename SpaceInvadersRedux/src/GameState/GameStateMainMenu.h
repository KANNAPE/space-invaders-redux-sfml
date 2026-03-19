#ifndef __GAME_STATE_MENU_H__
#define __GAME_STATE_MENU_H__

#include "GameStateBase.h"

class GameStateMenu : public GameStateBase
{
public:
	GameStateMenu();

	bool create() override;
	void update(float delta) override;

protected:
	enum class State
	{
		MainMenu,
		NewGame,
		LoadGame,
		Settings_Display,
		Settings_Audio,
		Credits,
		Quit,

		COUNT
	};

	State m_state;
};

#endif //__GAME_STATE_MENU_H__