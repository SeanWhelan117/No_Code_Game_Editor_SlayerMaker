#include "Wall.h"

Wall::Wall(int t_wallTextNum, sf::Vector2f t_wallPos, TextureManager& textureManager) : wallTextureNumber(t_wallTextNum), wallPos(t_wallPos), m_textureManager(textureManager)
{
	//wallTextureNumber = t_wallTextNum;
	loadFiles();
	setupWall(t_wallPos);
}

void Wall::loadFiles()
{
	wallTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\WALLS\\wallGrey.png"));
	wallTexture2 = m_textureManager.getTexture("ASSETS\\IMAGES\\WALLS\\wallBrown.png");
	wallTexture3 = m_textureManager.getTexture("ASSETS\\IMAGES\\WALLS\\wallRed.png");
	if (wallTextureNumber == 0)
	{
		wallSprite.setTexture(*wallTexture);
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

