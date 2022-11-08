#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Wall
{
public:
	Wall();

	void loadFiles();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);

	void render(sf::RenderWindow& t_window);

	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2i t_mousePos);

	void checkForPlacement();


	sf::Sprite wallSprites[100];

private:

	bool isClicked = false;
	int pickedWall;

	sf::Texture wallTexture;


};

