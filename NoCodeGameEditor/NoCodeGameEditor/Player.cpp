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
	player.setSize(sf::Vector2f(30, 50));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setPosition(gameSize.x / 2, gameSize.y / 2);

}

void Player::update()
{
	playerMovement();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(player);

}



void Player::playerMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		move(0, -speed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		move(0, speed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move(-speed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move(speed, 0);
	}

	player.setPosition(position);
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
