/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <fstream>

class ChooseGame
{
public:
	ChooseGame(float t_gameWidth, float t_gameHeight);

	void loadFont();

	void findFiles();

	void setupSprites();

	void setupNames();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);

	std::vector<sf::RectangleShape> games;
	int fileCount = 0;
private:

	float gameWidth = 0;
	float gameHeight = 0;
	sf::Vector2f initialPos = { 100, 100 };

	bool levelRectsCreated = false;
	std::vector <std::string> gameNames;


	std::vector<sf::Text> nameTexts;
	sf::Font font;
};

