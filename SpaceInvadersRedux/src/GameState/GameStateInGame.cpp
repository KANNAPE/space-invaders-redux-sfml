#include "GameStateInGame.h"
#include "Game/Game.h"

#include "Utils/Color.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

PlayerObject::PlayerObject()
{
	m_shape = sf::CircleShape(40.f, 3);
	m_shape.setFillColor(Utils::Color::Green);
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_shape, states);
}

bool GameStateInGame::create()
{
	if (!GameStateBase::create())
		return false;

	m_player = createObject<PlayerObject>();
	m_player->setPosition({ (float)DEFAULT_WINDOW_W / 2.f, 500.f });

	return true;
}
