#ifndef __GAME_STATE_MENU_H__
#define __GAME_STATE_MENU_H__

#include "GameStateBase.h"

#include "GameObject/UI/UIButton.h"
#include "GameObject/UI/UIText.h"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

class GameStateMainMenu : public GameStateBase
{
public:
	GameStateMainMenu();

	bool create() override;
	void update(float delta) override;

	void onValidateSelection() override;

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

	enum class ButtonType
	{
		NewGame,
		LoadGame,
		Settings,
		Credits,
		Quit,

		COUNT
	};

	State m_state;

	// UI
	UIText* m_menuTitle;
	std::vector<UIButton*> m_menuButtons;
};

#endif //__GAME_STATE_MENU_H__