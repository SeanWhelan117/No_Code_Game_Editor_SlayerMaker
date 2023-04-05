/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Clock
{
public:

	Clock();

	void loadFiles();

	void update(sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);

	


	void startClock();

	sf::Text clockText;
private:


	void setupClockDisplay();

	void addToClock();


	sf::String clockString;
	sf::Font clockFont;

	sf::Clock myClock;

	int minuteTens = 0;
	int minuteSingles = 0;
	int secondTens = 0;
	int secondSingles = 0;
	char colon = ':';

};

