/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(int t_enemyTextNum);

	void loadFiles();

	void setupEnemy(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);

	void update();
	sf::Sprite& getEnemy();

	void moveEnemy();

	sf::Texture enemyTexture;
	sf::Texture enemyTexture2;
	sf::Texture enemyTexture3;
private:

	sf::Sprite enemySprite;

	int offset = 15;

	int enemyTextureNumber = 0;
	sf::Texture currentTexture;

	int timesCalled = 0;
};

