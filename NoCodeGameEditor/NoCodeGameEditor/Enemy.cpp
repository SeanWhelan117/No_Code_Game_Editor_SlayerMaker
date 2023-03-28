#include "Enemy.h"

Enemy::Enemy(int t_EnemyTextNum, TextureManager& textureManager) : enemyTextureNumber(t_EnemyTextNum), m_textureManager(textureManager)
{
	loadFiles();
	//std::cout << "Enemy Created" << std::endl;
}

void Enemy::loadFiles()
{
	enemyTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy1-choice.png"));
	enemyTexture2 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY2\\Enemy2-choice.png"));
	enemyTexture3 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY3\\Enemy3-choice.png"));

	if (enemyTextureNumber == 0)
	{
		enemySprite.setTexture(*enemyTexture);
	}
	else if (enemyTextureNumber == 1)
	{
		enemySprite.setTexture(*enemyTexture2);

	}
	else if (enemyTextureNumber == 2)
	{
		enemySprite.setTexture(*enemyTexture3);
	}
}

void Enemy::setupEnemy(sf::Vector2f t_pos)
{
	enemySetup = true;
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setPosition(createRandomStartPos(t_pos));
	speed = createRandomSpeed();
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(enemySprite);
}

void Enemy::update(sf::Vector2f t_playerPos)
{
	moveEnemy(t_playerPos);
}

sf::Sprite& Enemy::getEnemy()
{
	return enemySprite;
}

void Enemy::moveEnemy(sf::Vector2f t_playerPos)
{

	sf::Vector2f currentPos = enemySprite.getPosition();

	if (currentPos.x < t_playerPos.x)
	{
		currentPos.x += speed;
	}
	else if (currentPos.x > t_playerPos.x)
	{
		currentPos.x -= speed;
	}

	if (currentPos.y < t_playerPos.y)
	{
		currentPos.y += speed;
	}
	else if (currentPos.y > t_playerPos.y)
	{
		currentPos.y -= speed;
	}
	
	enemySprite.setPosition(currentPos);
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

float Enemy::createRandomSpeed()
{
	float tempSpeed = 1.5f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (4.5f - 1.5f)));

	//std::cout << tempSpeed << std::endl;

	return tempSpeed;
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::setHealth(int t_damage)
{
	health -= t_damage;
}
