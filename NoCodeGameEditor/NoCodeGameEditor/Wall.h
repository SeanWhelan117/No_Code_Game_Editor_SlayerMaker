#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "ToolBar.h"

class Wall
{
public:
	Wall();

	void loadFiles();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<std::vector<Cell>>& t_grid, int t_gridParams, bool t_wallsPlaced);

	void render(sf::RenderWindow& t_window);

	void placeWallsOnGrid(std::vector<std::vector<Cell>>& t_grid, int t_gridParams);


	static const int MAX_WALLS = 900;
	sf::Sprite wallSprites[MAX_WALLS];

private:

	bool isClicked = false;
	int pickedWall;

	sf::Texture wallTexture;

	int offset = 15;

	int wallTemp = 0;

};

