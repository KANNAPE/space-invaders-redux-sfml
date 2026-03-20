#include "GameStateBase.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics/RenderStates.hpp>

bool GameStateBase::create()
{
	return true;
}

void GameStateBase::destroy()
{
	for (auto* gameObj : m_gameObjects)
		delete gameObj;
}

void GameStateBase::drawObjects(sf::RenderWindow& window)
{
	for (const auto* gameObj : m_gameObjects)
		window.draw(*gameObj);
}
