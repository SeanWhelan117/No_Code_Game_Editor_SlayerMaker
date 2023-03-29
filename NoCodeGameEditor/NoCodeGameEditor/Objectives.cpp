#include "Objectives.h"

Objectives::Objectives(int t_objectiveType, sf::Vector2f t_objectivePos, TextureManager& textureManager) : objectiveType(t_objectiveType), objectivePos(t_objectivePos), m_textureManager(textureManager)
{
	if (t_objectiveType == 0)
	{
		//coin
		Coin tempCoin(t_objectivePos, textureManager);
		coinVector.emplace_back(new Coin(tempCoin));
	}
	else if (t_objectiveType == 1)
	{
		Door tempDoor(t_objectivePos, textureManager);
		doorVector.emplace_back(new Door(tempDoor));
	}
	else if (t_objectiveType == 2)
	{
		Monument tempMonument(t_objectivePos, textureManager);
		monumentVector.emplace_back(new Monument(tempMonument));
	}

}
