/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ChoiceBar
{

public:
	ChoiceBar(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::string t_currentMode);

	void render(sf::RenderWindow& t_window);

	int currentChoice = 0;
	bool choiceMade = false;
private:
	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos);

	void resetTools(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeTools(int t_current);

	void setToolPosForView(sf::RenderWindow& t_window);

	float gameWidth = 0;
	float gameHeight = 0;

	sf::Sprite choiceBarSprite;
	sf::Texture choiceBarTexture;

	static const int MAX_CHOICES = 3;
	sf::Sprite wallChoiceSprite[MAX_CHOICES];
	sf::Sprite enemyChoiceSprite[MAX_CHOICES];

	sf::Texture wallChoiceTex1;
	sf::Texture wallChoiceTex2;
	sf::Texture wallChoiceTex3;

	sf::Texture enemyChoiceTex1;
	sf::Texture enemyChoiceTex2;
	sf::Texture enemyChoiceTex3;

	std::string currentMode = "WALLS";

	static const int MAX_OBJECTIVE_CHOICES = 2;

	sf::Sprite coinSprite;
	sf::Texture coinTexture;
	
	sf::Sprite doorSprite;
	sf::Texture doorTexture;

};

