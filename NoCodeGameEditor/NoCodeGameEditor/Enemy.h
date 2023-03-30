/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "TextureManager.h"
#include "Wall.h"

class Enemy
{
public:
	Animator myAnim;
	Enemy(int t_enemyTextNum, TextureManager& textureManager);

	void loadFiles();

	void setupEnemy(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);

	void update(sf::Vector2f t_playerPos, std::vector<std::unique_ptr<Wall>>& t_walls);
	sf::Sprite& getEnemy();

	void moveEnemy(sf::Vector2f t_playerPos);


	std::shared_ptr<sf::Texture> enemyTexture;
	std::shared_ptr<sf::Texture> enemyTexture2;
	std::shared_ptr<sf::Texture> enemyTexture3;

	bool enemySetup = false;

	int getHealth();
	void setHealth(int t_damage);
private:
	sf::Vector2f createRandomStartPos(sf::Vector2f t_spawnerPos);
	float createRandomSpeed();

	sf::Sprite enemySprite;

	int offset = 15;

	int enemyTextureNumber = 0;
	sf::Texture currentTexture;

	int timesCalled = 0;

	int randomSpawn = 0;

	float speed = 3.0f;
	TextureManager& m_textureManager;

	int health = 25;
};

