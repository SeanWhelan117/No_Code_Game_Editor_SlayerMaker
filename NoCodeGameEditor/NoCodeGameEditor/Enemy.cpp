#include "Enemy.h"

Enemy::Enemy(int t_EnemyTextNum, sf::Vector2f t_spawnerPos, TextureManager& textureManager) : enemyTextureNumber(t_EnemyTextNum), spawnerPosition(t_spawnerPos), m_textureManager(textureManager)
{
	loadFiles();
	setupEnemy(t_spawnerPos);
	setupVisionCone();
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
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	enemySprite.setPosition(createRandomStartPos(t_pos));
	speed = createRandomSpeed();
	enemySetup = true;
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(enemySprite);
	t_window.draw(visionCone);
}

void Enemy::update(sf::Vector2f t_playerPos, std::vector<std::unique_ptr<Wall>>& t_walls, sf::Time t_deltaTime)
{
	//moveEnemy(t_playerPos);
	if (seekingPlayer == true)
	{
		seeking(t_playerPos);
	}
	else
	{
		hasWallbeenDestroyed(t_walls);
	}


	checkCollisions(t_walls);

	visionCone.setRotation(enemySprite.getRotation() - 90);
	visionCone.setPosition(enemySprite.getPosition());
}

sf::Sprite& Enemy::getEnemy()
{
	return enemySprite;
}

void Enemy::seeking(sf::Vector2f t_playerPos)
{
	sf::Vector2f playerPosition = t_playerPos;
	sf::Vector2f seekerPosition = enemySprite.getPosition();


	float angleX = seekerPosition.x - playerPosition.x;
	float angleY = seekerPosition.y - playerPosition.y;

	float rotation = (-atan2(angleX, angleY)) * 180 / PI;
	enemySprite.setRotation(rotation);


	velocity = playerPosition - seekerPosition;
	float squareRootVelocity = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	velocity = sf::Vector2f{ velocity.x / squareRootVelocity , velocity.y / squareRootVelocity };
	velocity = velocity * speed;

	enemySprite.move(velocity);
}


void Enemy::attack(Wall* t_wall)
{
	if (attackTimer.getElapsedTime().asSeconds() >= attackRate) 
	{
		attackTimer.restart();
		t_wall->damageWall(damage);
	}

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

void Enemy::setupVisionCone()
{
	visionCone.setPointCount(3);
	visionCone.setPoint(0, sf::Vector2f(0, 0));
	visionCone.setPoint(1, sf::Vector2f(coneLength, -coneLength * std::tan(coneAngle / 2 * PI / 180)));
	visionCone.setPoint(2, sf::Vector2f(coneLength, coneLength * std::tan(coneAngle / 2 * PI / 180)));

	visionCone.setFillColor(sf::Color(0,0,0,0));
}

sf::ConvexShape Enemy::getVisionCone()
{
	return visionCone;
}

void Enemy::checkCollisions(std::vector<std::unique_ptr<Wall>>& t_walls)
{
	for (int i = 0; i < t_walls.size(); i++)
	{
		if (visionCone.getGlobalBounds().intersects(t_walls.at(i).get()->getWall().getGlobalBounds()))
		{
			seekingPlayer = false;
			attack(t_walls.at(i).get());
		}
	}
}

void Enemy::hasWallbeenDestroyed(std::vector<std::unique_ptr<Wall>>& t_walls)
{
	for (int i = 0; i < t_walls.size(); i++)
	{
		if (!visionCone.getGlobalBounds().intersects(t_walls.at(i).get()->getWall().getGlobalBounds()))
		{
			seekingPlayer = true;
		}
	}

}




