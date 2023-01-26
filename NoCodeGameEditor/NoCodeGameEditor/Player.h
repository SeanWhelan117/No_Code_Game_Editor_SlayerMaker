/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
public:

	Player(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void setupPlayer();

	void update();

	void render(sf::RenderWindow& t_window);

	sf::RectangleShape getPlayer();


private:
	void playerMovement();
	void move(float t_x, float t_y);
	sf::RectangleShape player;

	sf::Vector2f gameSize;

	int speed = 1;
	int speedX = 0;
	int speedY = 0;

	sf::Vector2f position = sf::Vector2f(0, 0);

};

