#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(int t_spawnerTextNum, sf::Vector2f t_spawnerPos, TextureManager& textureManager) : spawnerTextureNumber(t_spawnerTextNum), spawnerPos(t_spawnerPos), m_textureManager(textureManager)
{
	//std::cout << "EnemySpawner Created" << std::endl;
	spawnerTextureNumber = t_spawnerTextNum;
	loadFiles();
	setupSpawner(t_spawnerPos);
}

void EnemySpawner::loadFiles()
{
	spawnerTexture = m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy1Spawner.png");
	spawnerTexture2 = m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY2\\Enemy2Spawner.png");
	spawnerTexture3 = m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY3\\Enemy3Spawner.png");

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

void EnemySpawner::render(sf::RenderWindow& t_window, std::string t_state)
{
	t_window.draw(spawnerSprite);

	if (t_state == "test")
	{
		if (enemyVector.size() > 0)
		{
			for (int i = 0; i < enemyVector.size(); i++)
			{
				t_window.draw(enemyVector.at(i)->getEnemy());
			}
		}
	}
}

void EnemySpawner::update(sf::Vector2f t_playerPos)
{
	test++;

	if (test >= 100 )
	{
		test = 0;
		if (totalEnemies < MAX_ENEMIES)
		{
			enemyVector.push_back(new Enemy(createEnemy()));
			totalEnemies++;
		}
		
	}

	if (enemyVector.size() > 0)
	{
		for (int i = 0; i < enemyVector.size(); i++)
		{
			if (enemyVector.at(i)->enemySetup == false)
			{
				timesCalled++;
				enemyVector.at(i)->setupEnemy(getSpawner().getPosition());
			}
			enemyVector.at(i)->update(t_playerPos);
		}
	}
}

sf::Sprite& EnemySpawner::getSpawner()
{
	return spawnerSprite;
}

Enemy EnemySpawner::createEnemy()
{
	Enemy tempEnemy{ spawnerTextureNumber };

	return tempEnemy;
}