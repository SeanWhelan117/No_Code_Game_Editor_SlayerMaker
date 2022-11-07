#include "Wall.h"

Wall::Wall()
{
	loadFiles();
	wallSprite.setPosition(1750, 500);
	wallSprite.setTexture(wallTexture);
	wallSprite.setOrigin(wallSprite.getGlobalBounds().width / 2, wallSprite.getGlobalBounds().height / 2);}

void Wall::loadFiles()
{
	if (!wallTexture.loadFromFile("ASSETS\\IMAGES\\wallTest.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallTest)" << std::endl;
	}
}

void Wall::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	checkForMousePosAndClick(t_window);
}

void Wall::render(sf::RenderWindow& t_window)
{
	t_window.draw(wallSprite);
}

void Wall::checkForMousePosAndClick(sf::RenderWindow& t_window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(t_window);
	//std::cout << mousePos.x << mousePos.y << std::endl;
	
	if (wallSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << "YUP" << std::endl;
		}
	}
}