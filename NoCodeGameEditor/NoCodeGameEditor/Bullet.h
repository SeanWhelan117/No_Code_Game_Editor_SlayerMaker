/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	/// <summary>
	/// Bullet constructor, takes the sf window and the player position as parameters
	/// Sets up a mouse position at the time of the bullets instantiation
	/// sets up a player position at the time of the bullets instantiation
	/// calls setupSprites and createMovementVector
	/// </summary>
	/// <param name="t_window"></param>
	/// <param name="t_playerPos"></param>
	Bullet(sf::RenderWindow& t_window, sf::Vector2f t_playerPos);

	/// <summary>
	/// sets the simple fill color, size and initial position of the the bullet
	/// </summary>
	void setupSprites();

	/// <summary>
	/// moves the bullet based on the velocity it should have every update
	/// </summary>
	void update();

	/// <summary>
	/// draws the bullet every update
	/// </summary>
	/// <param name="t_window"></param>
	void render(sf::RenderWindow& t_window);

	/// <summary>
	///  simple getter to return the bullets rectangle shape
	/// </summary>
	/// <returns></returns>
	sf::RectangleShape getBullet();

private:
	/// <summary>
	/// uses a formula to create the movement vector which each bullet needs
	/// Creates a random offset for x and y for the heading of the bullet
	/// adds the random offset to the end position
	/// Movement vector is end position minus player position
	/// this is then normalised using the square root of the x times x plus y times y
	/// then the movement vector is divided by this number to create the velocity to be added each frame
	/// </summary>
	void createMovementVector();

	sf::Vector2f mousePos;
	sf::RectangleShape bullet;

	sf::Vector2f playerPosition;
	sf::Vector2f movementVector;

	sf::Vector2f velocity;
};

