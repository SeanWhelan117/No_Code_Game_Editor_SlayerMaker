/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Background
{
public:

	Background(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void update(int t_choice);

	void render(sf::RenderWindow& t_window);

	void setupBackground(int t_choice);

private:
	sf::Sprite bgSprite;

	sf::Texture bgTex1;
	sf::Texture bgTex2;
	sf::Texture bgTex3;

	int choice = -99;

	int gameWidth;
	int gameHeight;
};

