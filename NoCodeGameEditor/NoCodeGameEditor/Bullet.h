#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet
{
public:

	Bullet(sf::RenderWindow& t_window, sf::Vector2f t_playerPos);

	~Bullet();

	void loadFiles();

	void setupSprites();

	void update();

	void render(sf::RenderWindow& t_window);

	sf::RectangleShape getBullet();

private:
	void createMovementVector();

	sf::Vector2f mousePos;
	sf::RectangleShape bullet;

	sf::Vector2f playerPosition;
	sf::Vector2f movementVector;

	sf::Vector2f velocity;
};

