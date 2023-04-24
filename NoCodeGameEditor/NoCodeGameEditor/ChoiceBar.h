/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include "TextureManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class ChoiceBar
{

public:
	/// <summary>
	/// Choicebar constructor
	/// calls loadFiles and setup sprites
	/// takes game width and height as parameters
	/// </summary>
	/// <param name="t_gameWidth"></param>
	/// <param name="t_gameHeight"></param>
	ChoiceBar(float t_gameWidth, float t_gameHeight);

	/// <summary>
	/// loads all of the textures required for the choice bar
	/// This includes the bar itself, samples of all the walls, all the enemies,
	/// all the items, all the objectives and all the powerups
	/// </summary>
	void loadFiles();

	/// <summary>
	/// sets up the various sprites so that they are placed inside the choice bar with the correct
	/// scales origins and textures
	/// </summary>
	void setupSprites();

	/// <summary>
	/// checks if the chosen game type parameter doesnt equal the currentgameType. 
	/// If this is the case it is assigned.
	/// calls the function which makes sure all the tools are dynamic with the view
	/// sets the currentMode
	/// checks for mouse Position and clicks
	/// </summary>
	/// <param name="t_deltaTime"></param>
	/// <param name="t_window"></param>
	/// <param name="t_currentMode"></param>
	/// <param name="t_chosenGameType"></param>
	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::string t_currentMode, int t_chosenGameType);

	/// <summary>
	/// draws which ever ui elements should be in the choice bar at any time
	/// </summary>
	/// <param name="t_window"></param>
	void render(sf::RenderWindow& t_window);

	int currentChoice = 0;
	bool choiceMade = false;
	std::string currentMode = "WALLS";

	

private:
	/// <summary>
	/// calls process mouseclick for whichever mode the user is currently in.
	/// Passes the sprites they could have clicked
	/// </summary>
	/// <param name="t_window"></param>
	/// <param name="t_mousePos"></param>
	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos);

	/// <summary>
	/// If the object contains the mouse, increase scale,
	/// else decrease scale
	/// If the mouse left is pressed set current choice to the number of loops in the for loop
	/// also choice is now made
	/// </summary>
	/// <param name="t_object"></param>
	/// <param name="t_mousePos"></param>
	/// <param name="t_numLoops"></param>
	void processMouseClick(sf::FloatRect t_object, sf::Vector2f t_mousePos, int t_numLoops);

	/// <summary>
	/// resets the ui elements to original scale
	/// </summary>
	/// <param name="t_current"></param>
	void resetTools(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	/// <summary>
	/// increases ui elements scale
	/// </summary>
	/// <param name="t_current"></param>
	void changeTools(int t_current);

	/// <summary>
	/// makes sure the ui elements move dynamically with the view so the UI stays on screen at all times 
	/// </summary>
	/// <param name="t_window"></param>
	void setToolPosForView(sf::RenderWindow& t_window);

	float gameWidth = 0;
	float gameHeight = 0;

	sf::Sprite choiceBarSprite;

	static const int MAX_CHOICES = 3;
	sf::Sprite wallChoiceSprite[MAX_CHOICES];
	sf::Sprite enemyChoiceSprite[MAX_CHOICES];

	sf::Texture choiceBarTexture;

	sf::Texture wallChoiceTex1;
	sf::Texture wallChoiceTex2;
	sf::Texture wallChoiceTex3;

	sf::Texture enemyChoiceTex1;
	sf::Texture enemyChoiceTex2;
	sf::Texture enemyChoiceTex3;

	sf::Texture coinTexture;
	sf::Texture doorTexture;
	sf::Texture monumentTexture;

	sf::Texture medkitTexture;
	sf::Texture explosiveTexture;
	sf::Texture gunTexture;

	sf::Texture nukeTexture;
	sf::Texture invincibilityTexture;
	sf::Texture invisibilityTexture;

	static const int MAX_OBJECTIVE_CHOICES = 2;

	sf::Sprite coinSprite;
	
	sf::Sprite doorSprite;

	sf::Sprite monumentSprite;

	sf::Sprite medkitSprite;

	sf::Sprite gunSprite;

	sf::Sprite explosiveSprite;

	sf::Sprite nukeSprite;

	sf::Sprite invincibilitySprite;

	sf::Sprite invisibilitySprite;

	int chosenGT = 0;


};

