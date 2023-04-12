#include "Powerups.h"

Powerups::Powerups(TextureManager& textureManager) : m_textureManager(textureManager)
{
}

void Powerups::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect)
{
}

void Powerups::render(sf::RenderWindow& t_window)
{
}

void Powerups::addToVector(sf::Vector2f t_powerupPosition, int t_powerupType)
{
	if (t_powerupType == 0)
	{
		PUPNuke tempNuke(t_powerupPosition, m_textureManager);
		nukeVector.emplace_back(new PUPNuke(t_powerupType));
	}
	else if (t_powerupType == 1)
	{
		PUPInvincibility tempInvince(t_powerupPosition, m_textureManager, false);
		invinceVector.emplace_back(new PUPInvincibility(tempInvince));
	}
	else if (t_powerupType == 2)
	{
		PUPInvisibility tempInvis(t_powerupPosition, m_textureManager, false);
		invisVector.emplace_back(new PUPInvisibility(tempInvis));
	}
}

bool Powerups::isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2)
{
	return t_obj1.intersects(t_obj2);
}

void Powerups::playerCollision(sf::FloatRect t_playerRect)
{
}
