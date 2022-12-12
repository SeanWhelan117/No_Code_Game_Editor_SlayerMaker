#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ToolBar
{
public:
	ToolBar(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);

	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2i t_mousePos);

	void resetTools(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeTools(int t_currentTool);

private:

	sf::Sprite toolBarSprite;
	sf::Texture toolBarTexture;

	sf::Sprite brushToolSprite;
	sf::Texture brushToolTexture;

	sf::Sprite fillToolSprite;
	sf::Texture fillToolTexture;

	float gameWidth = 0;
	float gameHeight = 0;

	bool brushToolSelected = false;

};
