/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class HealthBar
{
public:
	HealthBar();

	void loadFiles();

	void update(sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);



	void minusHealth(int t_health);

	void plusHealth(int t_health);

	sf::Sprite healthBarSprite;
	sf::RectangleShape healthRect;

	bool gameOver = false;
private:
	void setupHealthBarSprite();
	void setupHealthRect();

	

	sf::Texture healthBarTexture;
	int fullHealthBar = 0;
	int currentHealth = 0;


};

