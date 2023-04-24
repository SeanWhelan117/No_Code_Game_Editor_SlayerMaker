#include "Bullet.h"

/// <summary>
/// Bullet constructor, takes the sf window and the player position as parameters
/// Sets up a mouse position at the time of the bullets instantiation
/// sets up a player position at the time of the bullets instantiation
/// calls setupSprites and createMovementVector
/// </summary>
/// <param name="t_window"></param>
/// <param name="t_playerPos"></param>
Bullet::Bullet(sf::RenderWindow& t_window, sf::Vector2f t_playerPos)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));

	playerPosition = t_playerPos;

	//std::cout << playerPosition.x << "--------" << playerPosition.y << std::endl;
	setupSprites();
	createMovementVector();
}

/// <summary>
/// sets the simple fill color, size and initial position of the the bullet
/// </summary>
void Bullet::setupSprites()
{
	bullet.setFillColor(sf::Color::Black);
	bullet.setSize(sf::Vector2f(6, 2));
	bullet.setPosition(playerPosition);
}

/// <summary>
/// moves the bullet based on the velocity it should have every update
/// </summary>
void Bullet::update()
{
	bullet.move(velocity.x * 15, velocity.y * 15);
}

/// <summary>
/// draws the bullet every update
/// </summary>
/// <param name="t_window"></param>
void Bullet::render(sf::RenderWindow& t_window)
{
	t_window.draw(bullet);
}

/// <summary>
///  simple getter to return the bullets rectangle shape
/// </summary>
/// <returns></returns>
sf::RectangleShape Bullet::getBullet()
{
	return bullet;
}

/// <summary>
/// uses a formula to create the movement vector which each bullet needs
/// Creates a random offset for x and y for the heading of the bullet
/// adds the random offset to the end position
/// Movement vector is end position minus player position
/// this is then normalised using the square root of the x times x plus y times y
/// then the movement vector is divided by this number to create the velocity to be added each frame
/// </summary>
void Bullet::createMovementVector()
{
	sf::Vector2f endPosition;

	int randXOffset = rand() % 25 - 15;
	int randYOffset = rand() % 25 - 15;

	endPosition.x = mousePos.x + randXOffset;
	endPosition.y = mousePos.y + randYOffset;

	movementVector.x = endPosition.x - playerPosition.x;
	movementVector.y = endPosition.y - playerPosition.y;

	float temp = sqrt(movementVector.x * movementVector.x + movementVector.y * movementVector.y);
	velocity.x = (movementVector.x / temp);
	velocity.y = (movementVector.y / temp);
}
