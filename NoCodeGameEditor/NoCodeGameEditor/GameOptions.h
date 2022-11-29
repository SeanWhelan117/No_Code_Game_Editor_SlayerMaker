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

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);


private:

	void setupButtonText(); // setups font colour all that stuff for the button text

	void setupContinueButton();

	void setupTriangles();

	void setupGridSizeBox();

	void mouseButtonCollision(sf::Vector2i t_mousePos, GameState& t_gameState); // checks for collision with the mouse and buttons.
	//if the mouse is hovering changes that specific button
	//resets changes when it leaves that button
	//checks for that buttons click aswell

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
	std::string chooseGridSize = "What size for game grid";
	static const int NUM_OF_TRIANGLES = 2;
	sf::Sprite triangles[NUM_OF_TRIANGLES];
	sf::Texture triangleTexture;
	sf::RectangleShape gridSizeBox;

	sf::FloatRect gridSizeTextRect;

	int offset = 5;

	/*sf::Text continueButtonText;
	std::string buttonText = "Continue";*/

};

