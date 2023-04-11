/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ExplosiveUI
{
public:
	ExplosiveUI();

	void loadFiles();

	void setupExplosiveUISprite();

	void update(sf::Time t_deltaTime, int t_explosivesCollected);

	void render(sf::RenderWindow& t_window);
	sf::Sprite explosiveUISprite;
private:

	static const int MAX_TEXTURES = 6;
	sf::Texture explosiveUITextures[MAX_TEXTURES];

	int currentNum = 0;
};

