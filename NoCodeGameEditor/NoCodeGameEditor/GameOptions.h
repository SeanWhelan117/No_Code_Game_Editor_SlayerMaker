/// <summary>
/// @author Sean Whelan
/// @date 2022/23
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

	int chosenBG = 0;
	int chosenGT = 0;

private:

	void setupText(); // setups font colour all that stuff for the button text

	void setupChooseBackgroundRect();
	
	void setupBGChoices();

	void setupContinueButton();

	void setupTriangles();

	void setupGridSizeBox();

	void setUpGameName();

	void setUpGameType();

	void setupGTChoices();

	void setUpChoiceRectangles();

	void checkForMousePos(GameState& t_gameState);


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

	sf::Text chooseBGText;
	sf::RectangleShape chooseBGRect;
	sf::FloatRect chooseBGTextRect;
	std::string chooseBGString = "Choose Game Background!";

	bool showBGChoices = false;

	static const int MAX_BG_CHOICES = 3;
	sf::Sprite bgChoiceSprite[MAX_BG_CHOICES];

	sf::Texture bgChoiceTex1;
	sf::Texture bgChoiceTex2;
	sf::Texture bgChoiceTex3;

	sf::RectangleShape choiceSquare;

	sf::Text gameTypeText;
	sf::String chooseGameTypeString = "Choose Game Type!";

	sf::RectangleShape gameTypeRect;

	bool showGameTypeChoices = false;

	static const int MAX_GAMETYPE_CHOICES = 3;
	sf::Sprite gameTypeChoiceSprite[MAX_GAMETYPE_CHOICES];

	sf::Texture gtChoiceTex1;
	sf::Texture gtChoiceTex2;
	sf::Texture gtChoiceTex3;

	sf::RectangleShape choiceSquare2;

	sf::RectangleShape choiceRectangles[2];


};

