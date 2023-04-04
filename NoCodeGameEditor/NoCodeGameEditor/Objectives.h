/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Coin.h"
#include "Door.h"
#include "Monument.h"

class Objectives
{

public:
	Objectives(TextureManager& textureManager);

	//void loadFiles();

	//void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect, int t_coinsCollected, int t_maxCoins);

	void render(sf::RenderWindow& t_window);

	std::vector<std::unique_ptr<Coin>> coinVector;
	std::vector<std::unique_ptr<Door>> doorVector;
	std::vector<std::unique_ptr<Monument>> monumentVector;

	void addToVector(sf::Vector2f t_objectivePosition, int t_objectiveType);

	bool isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2);

private:

	sf::Vector2f objectivePos;
	TextureManager& m_textureManager;

	void playerCollision(sf::FloatRect t_playerRect);

	bool allCoinsCollected = false;

	
};

