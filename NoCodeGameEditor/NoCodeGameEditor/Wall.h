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

	void checkForMousePosAndClick(sf::RenderWindow& t_window);


	sf::Sprite wallSprite;

private:



	sf::Texture wallTexture;


};

