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
#include "Monument.h"

class Enemy
{
public:
	Animator myAnim;
	Enemy(int t_enemyTextNum, sf::Vector2f t_spawnerPos, TextureManager& textureManager);

	void loadFiles();

	void setupEnemy(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);

	void update(sf::Vector2f t_seekPos, std::vector<std::unique_ptr<Wall>>& t_walls, sf::Time t_deltaTime, int t_gtChosen, std::vector<std::unique_ptr<Monument>>& t_monuments);
	sf::Sprite& getEnemy();


	void seeking(sf::Vector2f t_seekPos);


	std::shared_ptr<sf::Texture> enemyTexture;
	std::shared_ptr<sf::Texture> enemyTexture2;
	std::shared_ptr<sf::Texture> enemyTexture3;

	bool enemySetup = false;

	int getHealth();
	void setHealth(int t_damage);
	void setupVisionCone();
	sf::ConvexShape getVisionCone();
	void checkCollisions(std::vector<std::unique_ptr<Wall>>& t_walls, sf::Vector2f t_seekPos, int t_gtChosen, std::vector<std::unique_ptr<Monument>>& t_monuments);
	void hasWallbeenDestroyed(std::vector<std::unique_ptr<Wall>>& t_walls);
	bool seekingPlayer = true;
	bool attacking = false;

	void attack(Wall* t_wall);
	void attackMonument(Monument* t_monument);
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

	sf::Vector2f velocity;

	//float angle = 0;
	const float PI = 3.141592654f;
	//float speed = 6.0f;


	float coneAngle = 45;
	float coneLength = 30;
	sf::ConvexShape visionCone;


	float attackRate = 4.0f;
	int damage = 5;
	int damage2 = 1;
	sf::Clock attackTimer;

	sf::Vector2f spawnerPosition;
};

