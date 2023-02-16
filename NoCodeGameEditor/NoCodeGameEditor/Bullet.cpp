#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow& t_window, sf::Vector2f t_playerPos)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));

	playerPosition = t_playerPos;

	//std::cout << playerPosition.x << "--------" << playerPosition.y << std::endl;
	setupSprites();
	createMovementVector();
}

void Bullet::setupSprites()
{
	bullet.setFillColor(sf::Color::Black);
	bullet.setSize(sf::Vector2f(10, 10));
	bullet.setPosition(playerPosition);
}

void Bullet::update()
{
	bullet.move(velocity);
}

void Bullet::render(sf::RenderWindow& t_window)
{
	t_window.draw(bullet);

}

sf::RectangleShape Bullet::getBullet()
{
	return bullet;
}

void Bullet::createMovementVector()
{

	movementVector.x = mousePos.x - playerPosition.x;
	movementVector.y = mousePos.y - playerPosition.y;

	velocity.x = (movementVector.x * (1.0f / 30.0f));
	velocity.y = (movementVector.y * (1.0f / 30.0f));

}
