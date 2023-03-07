#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(int t_spawnerTextNum, sf::Vector2f t_spawnerPos)
{
	spawnerTextureNumber = t_spawnerTextNum;
	loadFiles();
	setupSpawner(t_spawnerPos);
}

void EnemySpawner::loadFiles()
{
	if (!spawnerTexture.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy1Spawner.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading spawnerTexture (Enemy1Spawner)" << std::endl;
	}

	if (!spawnerTexture2.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY2\\Enemy2Spawner.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading spawnerTexture2 (Enemy2-choice)" << std::endl;
	}

	if (!spawnerTexture3.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY3\\Enemy3Spawner.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading spawnerTexture3 (Enemy3Spawner)" << std::endl;
	}



	if (spawnerTextureNumber == 0)
	{
		spawnerSprite.setTexture(spawnerTexture);
	}
	else if (spawnerTextureNumber == 1)
	{
		spawnerSprite.setTexture(spawnerTexture2);
	}
	else if (spawnerTextureNumber == 2)
	{
		spawnerSprite.setTexture(spawnerTexture3);
	}
}

void EnemySpawner::setupSpawner(sf::Vector2f t_pos)
{
	spawnerSprite.setOrigin(spawnerSprite.getGlobalBounds().width / 2, spawnerSprite.getGlobalBounds().height / 2);
	spawnerSprite.setPosition(t_pos.x + offset, t_pos.y + offset);
	spawnerSprite.setScale(0.25, 0.25);

}

void EnemySpawner::render(sf::RenderWindow& t_window)
{
	t_window.draw(spawnerSprite);
}

sf::Sprite& EnemySpawner::getSpawner()
{
	return spawnerSprite;
}
