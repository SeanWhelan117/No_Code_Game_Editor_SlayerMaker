#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"

class Wall
{
public:
	Wall();

	void loadFiles();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<Cell>& t_grid);

	void render(sf::RenderWindow& t_window);

	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2i t_mousePos);

	void checkForPlacement(std::vector<Cell>& t_grid);

	void snapWallPositionToGrid(std::vector<Cell>& t_grid);


	sf::Sprite wallSprites[100];

private:

	bool isClicked = false;
	int pickedWall;

	sf::Texture wallTexture;


};

