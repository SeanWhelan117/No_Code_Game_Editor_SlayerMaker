#include "Powerups.h"

Powerups::Powerups(TextureManager& textureManager) : m_textureManager(textureManager)
{
}

void Powerups::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect)
{
}

void Powerups::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < nukeVector.size(); i++)
	{
		nukeVector.at(i).get()->render(t_window);
	}
	
	for (int i = 0; i < invinceVector.size(); i++)
	{
		invinceVector.at(i).get()->render(t_window);
	}
	
	for (int i = 0; i < invisVector.size(); i++)
	{
		invisVector.at(i).get()->render(t_window);
	}

}

void Powerups::addToVector(sf::Vector2f t_powerupPosition, int t_powerupType)
{
	if (t_powerupType == 0)
	{
		PUPNuke tempNuke(t_powerupPosition, m_textureManager);
		nukeVector.emplace_back(new PUPNuke(tempNuke));
	}
	else if (t_powerupType == 1)
	{
		PUPInvincibility tempInvince(t_powerupPosition, m_textureManager);
		invinceVector.emplace_back(new PUPInvincibility(tempInvince));
	}
	else if (t_powerupType == 2)
	{
		PUPInvisibility tempInvis(t_powerupPosition, m_textureManager);
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