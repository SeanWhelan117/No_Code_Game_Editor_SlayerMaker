#include "Objectives.h"

Objectives::Objectives(TextureManager& textureManager) : m_textureManager(textureManager)
{

}

void Objectives::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect)
{
	playerCollision(t_playerRect);
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
}
