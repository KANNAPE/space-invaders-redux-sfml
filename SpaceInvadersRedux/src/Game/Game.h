#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Player.h"

class Game
{
public:
	enum class State
	{
		E_Menu = 0,
		E_Settings,
		E_Game,
		E_Pause,

		E_COUNT,
	};

			Game();

	void	RunGame();

protected:
	void	ProcessEvents();
	void	Update(float _deltaTime);
	void	Render();

private:
	void	ProcessEvents_Menu();
	//void	ProcessEvents_Settings();
	//void	ProcessEvents_Game();
	//void	ProcessEvents_Pause();

	void	Update_Menu(float _deltaTime);
	//void	Update_Settings(float _deltaTime);
	//void	Update_Game(float _deltaTime);
	//void	Update_Pause(float _deltaTime);

	void	Render_Menu();
	//void	Render_Settings();
	//void	Render_Game();
	//void	Render_Pause();

	// Menu
	struct MenuState
	{
		enum class State
		{
			E_Menu_PressStart,
			E_Menu_NewGame,
			E_Menu_LoadGame,
			E_Menu_Credits
		};

		enum class ButtonType
		{
			E_NewGame,
			E_LoadGame,
			E_Settings,
			E_Credits,
			E_Quit,

			E_COUNT,
		};

		struct Button
		{
			Button(const sf::RectangleShape& shape, const sf::Text& text);

			sf::RectangleShape	m_shape;
			sf::Text			m_text;
		};

		MenuState();

		MenuState::State					m_menuState;
		sf::Font							m_menuTextFont;
		sf::Text							m_menuTitle;
		std::vector<Button>					m_menuButtons;
	};

	sf::RenderWindow	m_sfWindow;

	std::vector<State>	m_states;

	MenuState			m_menu;
};