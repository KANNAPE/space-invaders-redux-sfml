#include "GameStateInGame.h"
#include "Game/Game.h"

#include "GameObject/Player/Bullet.h"
#include "GameObject/Player/Player.h"
#include "Utils/Color.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

#define MAX_BULLET_POOL_SIZE 50

GameStateInGame::GameStateInGame()
	: m_player(nullptr)
	, m_bulletIdx(0)
{}

bool GameStateInGame::create()
{
	if (!GameStateBase::create())
		return false;

	m_player = createObject<Player>();
	m_player->setPosition({ (float)DEFAULT_WINDOW_W / 2.f, 500.f });

	for (int i = 0; i < MAX_BULLET_POOL_SIZE; ++i)
	{
		Bullet* bullet = createObject<Bullet>();
		bullet->setVisible(false);

		m_bulletPool.push_back(bullet);
	}

	return true;
}

void GameStateInGame::handleEvent(std::optional<sf::Event> event, sf::RenderWindow& window)
{
	GameStateBase::handleEvent(event, window);

	// key pressed
	if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->code == sf::Keyboard::Key::Space)
		{
			Bullet* newBullet = m_bulletPool[m_bulletIdx];
			newBullet->setVisible(true);

			newBullet->setPosition(m_player->getPosition());

			newBullet->shoot();

			m_bulletIdx = (m_bulletIdx + 1) % MAX_BULLET_POOL_SIZE;
		}
	}
}
