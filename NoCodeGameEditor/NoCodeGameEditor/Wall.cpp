#include "Wall.h"

Wall::Wall()
{
	loadFiles();
}

void Wall::loadFiles()
{
	if (!wallTexture.loadFromFile("ASSETS\\IMAGES\\WALLS\\wallGrey.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallGrey)" << std::endl;
	}

	if (!wallTexture2.loadFromFile("ASSETS\\IMAGES\\WALLS\\wallBrown.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallBrown)" << std::endl;
	}

	if (!wallTexture3.loadFromFile("ASSETS\\IMAGES\\WALLS\\wallRed.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallRed)" << std::endl;
	}
	
	
	wallSprite.setTexture(wallTexture);
}

void Wall::setupWall(sf::Vector2f t_pos)
{
	loadFiles();
	wallSprite.setTexture(wallTexture);
	wallSprite.setOrigin(wallSprite.getGlobalBounds().width / 2, wallSprite.getGlobalBounds().height / 2);
	wallSprite.setPosition(t_pos.x + offset, t_pos.y + offset);
}

sf::Sprite& Wall::getWall()
{
	return wallSprite;
}

