#include "GameStateBase.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics/RenderStates.hpp>


void GameStateBase::drawObjects(sf::RenderWindow& window)
{
	for (const auto* gameObj : m_gameObjects)
	{
		window.draw(*gameObj);
	}
}
