/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include "HealthBar.h"
class HUD
{

public:
	Clock myClock;
	HealthBar myHealthBar;
	HUD(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::Vector2f t_playerPos, bool& t_addHealth);

	void render(sf::RenderWindow& t_window);

 




private:
	void setUIElementsLocations(sf::RenderWindow& t_window, sf::Vector2f t_playerPos);

	float gameWidth = 0;
	float gameHeight = 0;
};

