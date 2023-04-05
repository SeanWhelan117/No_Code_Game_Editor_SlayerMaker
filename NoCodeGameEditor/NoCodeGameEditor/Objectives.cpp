#include "Objectives.h"

Objectives::Objectives(TextureManager& textureManager) : m_textureManager(textureManager)
{

}

void Objectives::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect, int t_coinsCollected, int t_maxCoins)
{

	//std::cout << "t_coinsCollected = " << t_coinsCollected << " t_maxCoins = " << t_maxCoins << std::endl;
	playerCollision(t_playerRect);
	if (t_coinsCollected >= t_maxCoins && allCoinsCollected == false && t_coinsCollected != 0)
	{
		allCoinsCollected = true;
		for (int i = 0; i < doorVector.size(); i++)
		{
			doorVector.at(i).get()->doorOpened();
		}
	}
	if (monumentVector.size() != 0)
	{
		monumentVector.at(0).get()->update();
	}
}

void Objectives::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < coinVector.size(); i++)
	{
		coinVector.at(i).get()->render(t_window);
	}
	for (int i = 0; i < doorVector.size(); i++)
	{
		doorVector.at(i).get()->render(t_window);
	}
	for (int i = 0; i < monumentVector.size(); i++)
	{
		monumentVector.at(i).get()->render(t_window);
	}


}

void Objectives::addToVector(sf::Vector2f t_objectivePosition, int t_objectiveType)
{

	if (t_objectiveType == 0)
	{
		Coin tempCoin(t_objectivePosition, m_textureManager);
		coinVector.emplace_back(new Coin(tempCoin));
	}
	else if (t_objectiveType == 1)
	{
		Door tempDoor(t_objectivePosition, m_textureManager);
		doorVector.emplace_back(new Door(tempDoor));
	}
	else if (t_objectiveType == 2)
	{
		Monument tempMonument(t_objectivePosition, m_textureManager);
		monumentVector.emplace_back(new Monument(tempMonument));
	}

}

bool Objectives::isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2)
{
	return t_obj1.intersects(t_obj2);
}

void Objectives::playerCollision(sf::FloatRect t_playerRect)
{
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
	}
}
