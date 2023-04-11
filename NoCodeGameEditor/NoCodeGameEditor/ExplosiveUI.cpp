#include "ExplosiveUI.h"

ExplosiveUI::ExplosiveUI()
{
	loadFiles();
	setupExplosiveUISprite();
}

void ExplosiveUI::loadFiles()
{
	
	if (!explosiveUITextures[0].loadFromFile("ASSETS\\IMAGES\\dynamiteUI0.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading explosiveUITextures (0)" << std::endl;
	}
	if (!explosiveUITextures[1].loadFromFile("ASSETS\\IMAGES\\dynamiteUI1.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading explosiveUITextures (1)" << std::endl;
	}
	if (!explosiveUITextures[2].loadFromFile("ASSETS\\IMAGES\\dynamiteUI2.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading explosiveUITextures (2)" << std::endl;
	}
	if (!explosiveUITextures[3].loadFromFile("ASSETS\\IMAGES\\dynamiteUI3.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading explosiveUITextures (3)" << std::endl;
	}
	if (!explosiveUITextures[4].loadFromFile("ASSETS\\IMAGES\\dynamiteUI4.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading explosiveUITextures (4)" << std::endl;
	}
	
}

void ExplosiveUI::setupExplosiveUISprite()
{
	explosiveUISprite.setPosition(50, 50);
	explosiveUISprite.setTexture(explosiveUITextures[0]);
	explosiveUISprite.setOrigin(explosiveUISprite.getLocalBounds().width / 2, explosiveUISprite.getLocalBounds().height / 2);
	explosiveUISprite.setScale(0.2, 0.2);
}

void ExplosiveUI::update(sf::Time t_deltaTime, int t_explosivesCollected)
{
	if (t_explosivesCollected != currentNum)
	{
		currentNum = t_explosivesCollected;
		if (currentNum < 5)
		{
			explosiveUISprite.setTexture(explosiveUITextures[currentNum]);
		}
	}
}

void ExplosiveUI::render(sf::RenderWindow& t_window)
{
	t_window.draw(explosiveUISprite);
}
