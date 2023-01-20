/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

#include "GameState.h"

class GameOptions
{
public:
	GameOptions(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, GameState& t_gameState);

	void render(sf::RenderWindow& t_window);

	static const int NUM_OF_TRIANGLES = 2;
	sf::Sprite triangles[NUM_OF_TRIANGLES];

	void changeGridSize(int t_triangleNum);

	int getGridSize();

	bool canType;
	std::string gameName = "";

private:

	void setupText(); // setups font colour all that stuff for the button text

	void setupContinueButton();

	void setupTriangles();

	void setupGridSizeBox();

	void setUpGameName();

	void checkForMousePos(GameState& t_gameState);

	void checkForKeyPress();



	void resetButtons(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeButtons(int current_Button);

	void changeGameState(int stateNum, GameState& t_gameState);


	sf::RectangleShape continueButton; // buttons array for menu buttons

	sf::Font m_font; //newyork.ttf font

	//text for each button stating what they are

	//just sf text array for the buttons


	sf::Vector2i mousePos; // mouses current position
	sf::Vector2f gameSize;

	sf::Text continueButtonText;
	std::string buttonText = "Continue";


	sf::Text chooseGridSizeText;
	std::string chooseGridSize = "What size for game grid?";

	sf::Text chooseGameNameText;
	std::string chooseGameName = "What is the name of your game?";
	
	sf::Texture triangleTexture;
	sf::RectangleShape gridSizeBox;

	sf::FloatRect gridSizeTextRect;

	static const int NUM_OF_GRIDSIZES= 5;

	sf::Text currentGridSize;
	std::string gridSizeNums[NUM_OF_GRIDSIZES] = { "30 x 30", "40 x 40", "50 x 50", "60 x 60", "70 x 70" };
	int currentGridStringNum = 0;
	int offset = 5;


	sf::Text gameNameText;

	sf::RectangleShape gameNameRect;


};

