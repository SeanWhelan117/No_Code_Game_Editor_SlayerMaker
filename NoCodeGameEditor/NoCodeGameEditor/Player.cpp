#include "Player.h"
Player::Player(float t_gameWidth, float t_gameHeight, Animator& t_animator):  m_animator(t_animator)
{
	gameSize.x = t_gameWidth;
	gameSize.y = t_gameHeight;
	loadFiles();
	setupPlayer();
}

void Player::loadFiles()
{
	if (!playerIdleTexture.loadFromFile("ASSETS\\IMAGES\\PLAYER\\PlayerIdle.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading playerIdleTexture (PlayerIdle)" << std::endl;
	}

	if (!playerWalkingTexture.loadFromFile("ASSETS\\IMAGES\\PLAYER\\PlayerWalking.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading playerWalkingTexture (PlayerWalking)" << std::endl;
	}
}

void Player::setupPlayer()
{
	playerSprite.setTexture(playerIdleTexture);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	playerSprite.setPosition(gameSize.x / 2, gameSize.y / 2);
	ogColor = playerSprite.getColor();
}

void Player::update(sf::RenderWindow& t_window, bool t_invincibilityActive, bool t_invisibilityActive)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));

	playerMovement();
	rotatePlayerView();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shoot(t_window);
	}

	if (bulletVector.size() > 0)
	{
		for (int i = 0; i < bulletVector.size(); i++)
		{
			bulletVector.at(i).get()->update();

			if (bulletVector.at(i).get()->getBullet().getPosition().x > gameSize.x ||
				bulletVector.at(i).get()->getBullet().getPosition().x < 0 ||
				bulletVector.at(i).get()->getBullet().getPosition().y > gameSize.y ||
				bulletVector.at(i).get()->getBullet().getPosition().y < 0)
			{
				removeBullet(i);
			}
		}
	}

	if (t_invincibilityActive)
	{
		if (colourChangeTimer.getElapsedTime().asMilliseconds() >= 500.0f)
		{
			colourChangeTimer.restart();

			sf::Color colour(std::rand() % 256, std::rand() % 256, std::rand() % 256);
			playerSprite.setColor(colour);

		}
	}
	

	if (t_invisibilityActive)
	{
		playerSprite.setColor(sf::Color(playerSprite.getColor().r, playerSprite.getColor().g, playerSprite.getColor().b, 25));
	}
	
	if(!t_invisibilityActive && !t_invincibilityActive)
	{
		playerSprite.setColor(ogColor);
	}
	//sf::Texture t_texture, int t_numOfFrames, int t_frameWidth, int t_frameHeight, int t_cols, int t_rows, int t_time

	textureRect = m_animator.animate(playerWalkingTexture, 5, 36, 53, 5, 1, 12);
	//playerSprite.setTextureRect(textureRect);
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(playerSprite);

	for (int i = 0; i < bulletVector.size(); i++)
	{
		t_window.draw(bulletVector.at(i).get()->getBullet());
	}
}

void Player::playerMovement()
{
	sf::Vector2f currentPos = playerSprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//speedY -= speed;
		currentPos.y -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//speedY += speed;
		currentPos.y += speed;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//speedX -= speed;
		currentPos.x -= speed;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//speedX += speed;
		currentPos.x += speed;
	}
	
	//move(speedX, speedY);

	//player.setPosition(position);
	playerSprite.setPosition(currentPos);
}

void Player::move(float t_x, float t_y) 
{
	position = playerSprite.getPosition();
	position.x += t_x;
	//updateAABB();
	//checkCollisions(); // collect info of all tiles player intersects with
	//resolveXCollisions();
	position.y += t_y;
	//updateAABB();
	//checkCollisions();
	//resolveYCollisions();
}

sf::Sprite Player::getPlayer()
{
	return playerSprite;
}

void Player::rotatePlayerView()
{
	sf::Vector2f playerPos = playerSprite.getPosition();

	float dx = playerPos.x - mousePos.x;
	float dy = playerPos.y - mousePos.y;
	double mouseAngle = static_cast<double>(-atan2(dx, dy)) * 180.0f / PI; //finding the angle that the mouse is at vs the players location
	playerSprite.setRotation(mouseAngle);
}

void Player::shoot(sf::RenderWindow& t_window)
{
	Bullet tempBullet{t_window, playerSprite.getPosition()};

	bulletVector.emplace_back(new Bullet(tempBullet));

}

void Player::removeBullet(int t_bulletNum)
{
	std::vector<std::unique_ptr<Bullet>>::iterator begin = bulletVector.begin();

	for (int i = 0; i < t_bulletNum ; i++)
	{
		begin++;
	}
	bulletVector.erase(begin);
}
