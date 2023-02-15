#include "Wall.h"

Wall::Wall(int t_wallTextNum)
{
	wallTextureNumber = t_wallTextNum;
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
	
	if (wallTextureNumber == 0)
	{
		wallSprite.setTexture(wallTexture);
	}
	else if (wallTextureNumber == 1)
	{
		wallSprite.setTexture(wallTexture2);
	}
	else if (wallTextureNumber == 2)
	{
		wallSprite.setTexture(wallTexture3);
	}
}

void Wall::setupWall(sf::Vector2f t_pos)
{
	loadFiles();
	wallSprite.setTexture(wallTexture);
	wallSprite.setOrigin(wallSprite.getGlobalBounds().width / 2, wallSprite.getGlobalBounds().height / 2);
	wallSprite.setPosition(t_pos.x + offset, t_pos.y + offset);
}

void Wall::render(sf::RenderWindow& t_window)
{
	t_window.draw(wallSprite);
}

sf::Sprite& Wall::getWall()
{
	return wallSprite;
}

