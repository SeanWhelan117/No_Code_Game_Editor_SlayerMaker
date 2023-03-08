/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class EnemySpawner
{

public:
	EnemySpawner(int t_spawnerTextNum, sf::Vector2f t_spawnerPos);

	void loadFiles();

	void setupSpawner(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);

	void update();

	sf::Sprite& getSpawner();

	Enemy createEnemy();

	sf::Texture spawnerTexture;
	sf::Texture spawnerTexture2;
	sf::Texture spawnerTexture3;

	std::vector<Enemy*> enemyVector;

	int spawnerTextureNumber = 0;
private:

	sf::Sprite spawnerSprite;

	int offset = 15;


	int test = 0;

	int totalEnemies = 0;
	static const int MAX_ENEMIES = 10;
	int timesCalled = 0;

};

