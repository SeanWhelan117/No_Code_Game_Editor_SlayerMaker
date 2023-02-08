#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ChoiceBar
{

public:
	ChoiceBar(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);

private:
	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos);

	void resetTools(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeTools(int t_currentTool);

	void setToolPosForView(sf::RenderWindow& t_window);

	float gameWidth = 0;
	float gameHeight = 0;

	sf::Sprite choiceBarSprite;
	sf::Texture choiceBarTexture;

};

