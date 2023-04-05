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
#include "LoadFromFile.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class ChooseGame
{
public:

	ChooseGame(float t_gameWidth, float t_gameHeight);
	LoadFromFile loader;

	void loadFont();

	void findFiles();

	void setupSprites();

	void setupNames();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);

	void checkForMousePos();


	std::vector<sf::RectangleShape> games;
	int fileCount = 0;

	bool gameChosen = false;
private:
	void setupBuildButtons();

	void buildGame(int t_game);

	float gameWidth = 0;
	float gameHeight = 0;
	sf::Vector2f initialPos = { 100, 100 };

	bool levelRectsCreated = false;
	std::vector <std::string> gameNames;

	std::vector<sf::Text> nameTexts;
	sf::Font font;

	sf::Vector2f mousePos;

	std::vector <sf::RectangleShape> buildButtons;
	bool gameBuilt = false;
};

