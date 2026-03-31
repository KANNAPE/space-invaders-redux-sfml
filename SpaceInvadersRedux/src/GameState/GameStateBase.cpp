#include "GameStateBase.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics/RenderStates.hpp>

GameStateBase::GameStateBase()
	: m_selection(nullptr)
{}

bool GameStateBase::create()
{
	return true;
}

void GameStateBase::destroy()
{
	for (int i = 0; i < m_gameObjects.size(); ++i)
		delete m_gameObjects[i];
}

void GameStateBase::handleEvent(std::optional<sf::Event> event, sf::RenderWindow& window)
{
	// mouse moved
	if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
	{
		sf::Vector2f mousePos = window.mapPixelToCoords(mouseMoved->position);

		for (auto* uiObj : m_uiObjects)
		{
			bool isCursorInside = uiObj->getBounds().contains(mousePos);
			if (isCursorInside && m_selection != uiObj)
			{
				onSelectionChanged(uiObj);
			}
			else if (!isCursorInside && m_selection == uiObj)
			{
				onSelectionChanged(nullptr);
			}
		}
	}

	// mouse clicked
	if (const auto* mouseClicked = event->getIf<sf::Event::MouseButtonReleased>())
	{
		if (m_selection != nullptr)
		{
			onValidateSelection();
		}
	}
}

void GameStateBase::update(float delta)
{
	for (auto* gameObj : m_gameObjects)
		gameObj->update(delta);
}

void GameStateBase::onSelectionChanged(UIObject* newSelection)
{
	// Selecting new selection if it's valid
	if (newSelection != nullptr)
		newSelection->onSelect();

	// Unselecting and updating last selected object
	if (m_selection != nullptr)
		m_selection->onUnselect();

	m_selection = newSelection;
}

void GameStateBase::onValidateSelection()
{
	if (m_selection != nullptr)
		m_selection->onValidate();
}

void GameStateBase::onValidateBack()
{}

void GameStateBase::drawObjects(sf::RenderWindow& window)
{
	for (const auto* gameObj : m_gameObjects)
	{
		if (gameObj != nullptr && gameObj->isVisible())
			window.draw(*gameObj);
	}
}
