/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Monument
{

public:
	Monument(sf::Vector2f t_monumentPos, TextureManager& textureManager);

	void loadFiles();

	void setupMonument();

	void render(sf::RenderWindow& t_window);

	void update();
	sf::Sprite& getMonument();

	void damageMonument(int t_damage);

	std::shared_ptr<sf::Texture> monumentTexture;

	bool gameOver = false;
private:

	void setupHealthBar();


	void changeColours();

	//int getMonumentHealth();

	TextureManager& m_textureManager;
	sf::Vector2f monumentPos;
	sf::Sprite monumentSprite;

	sf::RectangleShape monumentHealthBar;
	int maxMonumentHealth = 5000;
	int currentMonumentHealth = 5000;
};

