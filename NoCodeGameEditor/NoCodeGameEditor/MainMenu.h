/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

#include "GameState.h"
class MainMenu
{
public:

	MainMenu(float t_gameWidth, float t_gameHeight);
	void loadAssets();

	void update(GameState& t_gameState, sf::RenderWindow& t_window);
	void render(sf::RenderWindow& t_window);


private:

	void setupButtonText(int t_yPos); // setups font colour all that stuff for the button text

	void mouseButtonCollision(sf::Vector2i t_mousePos, GameState& t_gameState); // checks for collision with the mouse and buttons.
	//if the mouse is hovering changes that specific button
	//resets changes when it leaves that button
	//checks for that buttons click aswell

	void resetButtons(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeButtons(int current_Button);

	void changeGameState(int stateNum, GameState& t_gameState);


	static const int MAX_BUTTONS = 4;
	sf::RectangleShape buttons[MAX_BUTTONS]; // buttons array for menu buttons

	sf::Font m_font; // arial.ttf font
	sf::Font m_font2;

	//text for each button stating what they are

	//just sf text array for the buttons

	sf::Text buttonTexts[MAX_BUTTONS];
	sf::Text title;

	sf::Vector2i mousePos; // mouses current position



	
	float spriteX = 0; //the x and y size of every specific sprite in the spritesheet 
	float spriteY = 0;

	std::string buttonText[MAX_BUTTONS] = { "Create","Play","Options","Exit" };
	std::string titleText = "Slayer Maker";

};

