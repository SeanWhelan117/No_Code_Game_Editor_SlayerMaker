#include "Enemy.h"

Enemy::Enemy(int t_EnemyTextNum)
{
	enemyTextureNumber = t_EnemyTextNum;
	loadFiles();
	//std::cout << "Enemy Created" << std::endl;
}

void Enemy::loadFiles()
{
	if (!enemyTexture.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy1-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyTexture (Enemy1-choice)" << std::endl;
	}

	if (!enemyTexture2.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY2\\Enemy2-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyTexture2 (Enemy2-choice)" << std::endl;
	}

	if (!enemyTexture3.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY3\\Enemy3-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyTexture3 (Enemy3-choice)" << std::endl;
	}



	if (enemyTextureNumber == 0)
	{
		enemySprite.setTexture(enemyTexture);
		currentTexture = enemyTexture;
	}
	else if (enemyTextureNumber == 1)
	{
		enemySprite.setTexture(enemyTexture2);
		currentTexture = enemyTexture2;

	}
	else if (enemyTextureNumber == 2)
	{
		enemySprite.setTexture(enemyTexture3);
		currentTexture = enemyTexture3;
	}
}

void Enemy::setupEnemy(sf::Vector2f t_pos)
{
	//loadFiles();
	enemySetup = true;
	enemySprite.setTexture(currentTexture);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setPosition(createRandomStartPos(t_pos));
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(enemySprite);
}

void Enemy::update()
{
	moveEnemy();
}

sf::Sprite& Enemy::getEnemy()
{
	return enemySprite;
}

void Enemy::moveEnemy()
{

	sf::Vector2f currentPos = getEnemy().getPosition();

	
	currentPos.y += 1;
	currentPos.x += 1;

	//move(speedX, speedY);

	//player.setPosition(position);
	getEnemy().setPosition(currentPos);
}

sf::Vector2f Enemy::createRandomStartPos(sf::Vector2f t_spawnerPos)
{
	sf::Vector2f spawnPos = t_spawnerPos;

	randomSpawn = rand() % 4 + 1;

	if (randomSpawn == 1) // NORTH
	{
		spawnPos.y -= 60;
	}
	else if (randomSpawn == 2) // SOUTH
	{
		spawnPos.y += 60;
	}
	else if (randomSpawn == 3) // EAST
	{
		spawnPos.x += 60;
	}
	else if (randomSpawn == 4) // WEST
	{
		spawnPos.x -= 60;
	}
	else
	{
		std::cout << "Error with random pos for enemy" << std::endl;
	}

	return spawnPos;
}