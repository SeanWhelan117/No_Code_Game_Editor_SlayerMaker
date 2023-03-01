#include "Enemy.h"


Enemy::Enemy(int t_EnemyTextNum)
{
	enemyTextureNumber = t_EnemyTextNum;
	loadFiles();
}

void Enemy::loadFiles()
{
	if (!enemyTexture.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy1-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyTexture (Enemy1-choice)" << std::endl;
	}

	if (!enemyTexture2.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy2-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyTexture2 (Enemy2-choice)" << std::endl;
	}

	if (!enemyTexture3.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy3-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyTexture3 (Enemy3-choice)" << std::endl;
	}



	if (enemyTextureNumber == 0)
	{
		enemySprite.setTexture(enemyTexture);
	}
	else if (enemyTextureNumber == 1)
	{
		enemySprite.setTexture(enemyTexture2);
	}
	else if (enemyTextureNumber == 2)
	{
		enemySprite.setTexture(enemyTexture3);
	}
}

void Enemy::setupEnemy(sf::Vector2f t_pos)
{
	loadFiles();
	enemySprite.setTexture(enemyTexture);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setPosition(t_pos.x + offset, t_pos.y + offset);
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(enemySprite);
}

sf::Sprite& Enemy::getEnemy()
{
	return enemySprite;
}