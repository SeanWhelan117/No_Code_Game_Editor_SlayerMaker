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
#include "NetworkManager.h"


class ChooseGame
{
public:

	ChooseGame(float t_gameWidth, float t_gameHeight, NetworkManager& t_networkManager);
	LoadFromFile loader;

	void loadFontAndSprites();

	void findFiles();

	void setupSprites();

	void setupNames();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);

	bool containsMouse(sf::FloatRect t_rectShape);

	void checkForMousePos();

	void resetButtons(sf::RectangleShape& t_rect); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeButtons(sf::RectangleShape& t_rect);

	std::vector<sf::RectangleShape> games;
	int fileCount = 0;

	bool gameChosen = false;
	bool gameBuilt = false;

	std::string chosenGame;
	bool buttonClicked = false;
private:
	NetworkManager& m_networkManager;

	void setupButtons();

	void deleteFile(std::string t_filename);

	float gameWidth = 0;
	float gameHeight = 0;
	sf::Vector2f initialPos = { 200, 300 };

	bool levelRectsCreated = false;
	std::vector <std::string> gameNames;

	std::vector<sf::Text> nameTexts;
	sf::Text titleText;
	sf::Font font;

	sf::Vector2f mousePos;

	std::vector <sf::RectangleShape> buildButtons;
	std::vector <sf::RectangleShape> uploadButtons;
	std::vector <sf::RectangleShape> deleteButtons;
	std::vector <sf::RectangleShape> bgRects;

	sf::Texture buildTexture;
	sf::Texture uploadTexture;
	sf::Texture deleteTexture;

	std::vector <sf::Sprite> buildSprites;
	std::vector <sf::Sprite> uploadSprites;
	std::vector <sf::Sprite> deleteSprites;

	sf::RectangleShape downloadButton;
	float offset;
	sf::Vector2f buttonSize;

};

