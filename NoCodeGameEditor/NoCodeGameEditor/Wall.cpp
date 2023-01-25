#include "Wall.h"

Wall::Wall()
{
	loadFiles();
}

void Wall::loadFiles()
{
	if (!wallTexture.loadFromFile("ASSETS\\IMAGES\\wallTest.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallTest)" << std::endl;
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

