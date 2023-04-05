/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class GameOver
{
public:
	GameOver(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void update(sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);


	int buttonPressed = -10;
	
private:
	void setupButtons();
	void setupButtonText();
	void checkForMousePosAndClick();
	float gameWidth; 
	float gameHeight;

	static const int MAX_BUTTONS = 2;
	sf::RectangleShape buttons[MAX_BUTTONS];

	sf::Text button1Text;
	sf::Text button2Text;

	sf::Font buttonFont;
	sf::Vector2f mousePos;


};

