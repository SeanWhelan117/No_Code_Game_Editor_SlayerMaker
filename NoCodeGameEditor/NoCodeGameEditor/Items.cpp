#include "Items.h"

Items::Items(TextureManager& textureManager) : m_textureManager(textureManager)
{

}

void Items::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect)
{

}

void Items::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < medkitVector.size(); i++)
	{
		medkitVector.at(i).get()->render(t_window);
	}

	for (int i = 0; i < explosiveVector.size(); i++)
	{
		explosiveVector.at(i).get()->render(t_window);
	}
}

void Items::addToVector(sf::Vector2f t_itemPosition, int t_itemType)
{

	if (t_itemType == 0)
	{
		Medkit tempMedkit(t_itemPosition, m_textureManager);
		medkitVector.emplace_back(new Medkit(tempMedkit));
	}
	else if (t_itemType == 1)
	{
		Explosive tempExplosive(t_itemPosition, m_textureManager);
		explosiveVector.emplace_back(new Explosive(tempExplosive));
	}
	
}

bool Items::isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2)
{
	return t_obj1.intersects(t_obj2);
}

void Items::playerCollision(sf::FloatRect t_playerRect)
{
	/*
	for (int i = 0; i < coinVector.size(); i++)
	{
		if (coinVector.at(i).get()->getCoin().getGlobalBounds().intersects(t_playerRect))
		{
			std::vector<std::unique_ptr<Coin>>::iterator begin = coinVector.begin();
			begin += i;
			coinVector.erase(begin);
		}
	}

	for (int i = 0; i < doorVector.size(); i++)
	{
		if (doorVector.at(i).get()->doorAccesible == true)
		{
			if (isColliding(doorVector.at(i).get()->getDoor().getGlobalBounds(), t_playerRect))
			{
				std::cout << "GameOver" << std::endl;
				gameOver = true;
			}
		}
	}*/
}
