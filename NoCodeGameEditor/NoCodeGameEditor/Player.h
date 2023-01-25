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


private:
	void playerMovement();
	sf::RectangleShape player;

	sf::Vector2f gameSize;

	int speed = 5;

};

