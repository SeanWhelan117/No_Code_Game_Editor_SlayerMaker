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
	ChoiceBar(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::string t_currentMode, int t_chosenGameType);

	void render(sf::RenderWindow& t_window);

	int currentChoice = 0;
	bool choiceMade = false;
	std::string currentMode = "WALLS";

	

private:
	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos);

	void processMouseClick(sf::FloatRect t_object, sf::Vector2f t_mousePos, int t_numLoops);

	void resetTools(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeTools(int t_current);

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

