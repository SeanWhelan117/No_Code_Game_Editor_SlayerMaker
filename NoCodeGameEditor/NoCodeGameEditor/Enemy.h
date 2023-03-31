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

	void update(sf::Vector2f t_playerPos, std::vector<std::unique_ptr<Wall>>& t_walls, sf::Time t_deltaTime);
	sf::Sprite& getEnemy();


	void seeking(sf::Vector2f t_playerPos, sf::Time t_deltaTime);


	std::shared_ptr<sf::Texture> enemyTexture;
	std::shared_ptr<sf::Texture> enemyTexture2;
	std::shared_ptr<sf::Texture> enemyTexture3;

	bool enemySetup = false;

	int getHealth();
	void setHealth(int t_damage);
	void setupVisionCone();
private:

	void checkWallCollision(std::vector<std::unique_ptr<Wall>>& t_walls);

	void attackWall(std::vector<std::unique_ptr<Wall>>& t_walls, int t_wallToAttack);


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

	sf::Vector2f velocity;

	//float angle = 0;
	const float PI = 3.141592654f;
	//float speed = 6.0f;


	float coneAngle = 45;
	float coneLength = 30;
	sf::ConvexShape visionCone;

	bool seekingPlayer = true;

	bool attacking = false;

	int attackFatigue = 0;

	bool hit = false;

};

