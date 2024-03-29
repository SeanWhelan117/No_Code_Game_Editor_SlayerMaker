/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Crosshair
{
public:
	Crosshair();

	void loadFiles();

	void update(sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);

private:
	void setupCrosshair();

	sf::Sprite crosshair;
	sf::Texture crosshairTexture;

	sf::Vector2f mousePos;
};

