#include "Powerups.h"

Powerups::Powerups(TextureManager& textureManager) : m_textureManager(textureManager)
{
	setupNukeFlash();
}

void Powerups::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect)
{
	playerCollision(t_playerRect);

	if (nukeEnemies == true)
	{
		flashActive = true;
	}

	if (flashActive == true)
	{
		//std::cout << "NukeLocation " << tempNukeLocation.x << " --- " << tempNukeLocation.y << std::endl;
		nukeFlash.setPosition(tempNukeLocation);
		if (nukeFlash.getScale().x <= 600)
		{
			nukeFlash.setPosition(tempNukeLocation);
			nukeFlash.setScale(nukeFlash.getScale().x + 10, nukeFlash.getScale().y + 10);
			if (nukeFlash.getFillColor().a < 253)
			{
				nukeFlash.setFillColor(sf::Color(255, 255, 255, nukeFlash.getFillColor().a + 3));
			}
		}
		else
		{
			setupNukeFlash();
		}
	}

	if (invincibilityActive)
	{
		if (invinceTimer.getElapsedTime().asSeconds() >= 8)
		{
			invincibilityActive = false;
			invinceTimer.restart();
		}
	}

	if (invisibilityActive)
	{
		if (invisTimer.getElapsedTime().asSeconds() >= 8)
		{
			invisibilityActive = false;
			invisTimer.restart();
		}
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		invisibilityActive = true;
		invisTimer.restart();
	}*/
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

	t_window.draw(nukeFlash);

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

	for (int i = 0; i < nukeVector.size(); i++)
	{
		if (isColliding(nukeVector.at(i).get()->getNuke().getGlobalBounds(), t_playerRect))
		{
			tempNukeLocation = nukeVector.at(i).get()->getNuke().getPosition();
			std::vector<std::unique_ptr<PUPNuke>>::iterator begin = nukeVector.begin();
			begin += i;
			nukeVector.erase(begin);
			nukeEnemies = true;
		}
	}

	for (int i = 0; i < invinceVector.size(); i++)
	{
		if (isColliding(invinceVector.at(i).get()->getInvincibility().getGlobalBounds(), t_playerRect))
		{
			std::vector<std::unique_ptr<PUPInvincibility>>::iterator begin = invinceVector.begin();
			begin += i;
			invinceVector.erase(begin);
			invincibilityActive = true;
			invinceTimer.restart();
		}
	}

	for (int i = 0; i < invisVector.size(); i++)
	{
		if (isColliding(invisVector.at(i).get()->getInvisibility().getGlobalBounds(), t_playerRect))
		{
			std::vector<std::unique_ptr<PUPInvisibility>>::iterator begin = invisVector.begin();
			begin += i;
			invisVector.erase(begin);
			invisibilityActive = true;
			invisTimer.restart();
		}
	}
}

void Powerups::setupNukeFlash()
{
	flashActive = false;
	nukeFlash.setPosition(-10000, -10000);
	nukeFlash.setRadius(10);
	nukeFlash.setScale(1,1);
	nukeFlash.setOrigin(nukeFlash.getRadius() / 2, nukeFlash.getRadius() / 2);
	nukeFlash.setFillColor(sf::Color(255, 255, 255, 30));
}
