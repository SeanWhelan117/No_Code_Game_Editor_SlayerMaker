#include "Player.h"

Player::Player(float t_gameWidth, float t_gameHeight)
{
	gameSize.x = t_gameWidth;
	gameSize.y = t_gameHeight;

	loadFiles();
	setupPlayer();

}

void Player::loadFiles()
{
}

void Player::setupPlayer()
{
	player.setFillColor(sf::Color::Green);
	player.setSize(sf::Vector2f(30, 30));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setPosition(gameSize.x / 2, gameSize.y / 2);

}

void Player::update(sf::RenderWindow& t_window)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));

	playerMovement();
	rotatePlayerView();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shoot(t_window);
	}

	for (int i = 0; i < bulletVector.size(); i++)
	{
		bulletVector.at(i).update();
	}
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(player);

	for (int i = 0; i < bulletVector.size(); i++)
	{
		t_window.draw(bulletVector.at(i).getBullet());
	}
}

void Player::playerMovement()
{
	sf::Vector2f currentPos = player.getPosition();

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
	player.setPosition(currentPos);
}

void Player::move(float t_x, float t_y) 
{
	position = player.getPosition();
	position.x += t_x;
	//updateAABB();
	//checkCollisions(); // collect info of all tiles player intersects with
	//resolveXCollisions();
	position.y += t_y;
	//updateAABB();
	//checkCollisions();
	//resolveYCollisions();
}

sf::RectangleShape Player::getPlayer()
{
	return player;
}

void Player::rotatePlayerView()
{
	sf::Vector2f playerPos = player.getPosition();

	float dx = playerPos.x - mousePos.x;
	float dy = playerPos.y - mousePos.y;
	double mouseAngle = static_cast<double>(-atan2(dx, dy)) * 180.0f / PI; //finding the angle that the mouse is at vs the players location
	player.setRotation(mouseAngle + 180.0f);
}

void Player::shoot(sf::RenderWindow& t_window)
{
	Bullet tempBullet{t_window, player.getPosition()};

	bulletVector.push_back(tempBullet);
}
