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
	Objectives(int t_objectiveType, sf::Vector2f t_objectivePos, TextureManager& textureManager);

	/*void loadFiles();

	void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);*/

	std::vector<std::unique_ptr<Coin>> coinVector;
	std::vector<std::unique_ptr<Door>> doorVector;
	std::vector<std::unique_ptr<Monument>> monumentVector;

private:

	int objectiveType;
	sf::Vector2f objectivePos;
	TextureManager& m_textureManager;

};

