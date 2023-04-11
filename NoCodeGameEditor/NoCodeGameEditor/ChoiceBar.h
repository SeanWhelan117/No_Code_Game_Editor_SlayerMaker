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
	ChoiceBar(float t_gameWidth, float t_gameHeight, TextureManager& textureManager);

	void loadFiles();

	void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::string t_currentMode, int t_chosenGameType);

	void render(sf::RenderWindow& t_window);

	int currentChoice = 0;
	bool choiceMade = false;
	std::string currentMode = "WALLS";

	std::shared_ptr<sf::Texture> choiceBarTexture;

	std::shared_ptr<sf::Texture> wallChoiceTex1;
	std::shared_ptr<sf::Texture> wallChoiceTex2;
	std::shared_ptr<sf::Texture> wallChoiceTex3;

	std::shared_ptr<sf::Texture> enemyChoiceTex1;
	std::shared_ptr<sf::Texture> enemyChoiceTex2;
	std::shared_ptr<sf::Texture> enemyChoiceTex3;

	std::shared_ptr<sf::Texture> coinTexture;
	std::shared_ptr<sf::Texture> doorTexture;
	std::shared_ptr<sf::Texture> monumentTexture;

	std::shared_ptr<sf::Texture> medkitTexture;
	std::shared_ptr<sf::Texture> explosiveTexture;
	std::shared_ptr<sf::Texture> gunTexture;

private:
	TextureManager& m_textureManager;
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




	static const int MAX_OBJECTIVE_CHOICES = 2;

	sf::Sprite coinSprite;
	
	sf::Sprite doorSprite;

	sf::Sprite monumentSprite;

	sf::Sprite medkitSprite;

	sf::Sprite gunSprite;

	sf::Sprite explosiveSprite;

	int chosenGT = 0;


};

