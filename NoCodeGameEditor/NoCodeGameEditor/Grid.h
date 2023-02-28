/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#include "Cell.h"
#include <vector>
using namespace std;


class Grid
{
	Cell* myCell;


	const static int MAX_CELLS = 900;
	const static int MAX_ROWS = 30;
	const static int MAX_COLS = 30;

	float gameWidth = 0;
	float gameHeight = 0;

public:
	std::vector<std::vector<Cell>> theGrid;

	Grid(float t_gameWidth, float t_gameHeight);

	void setupGrid(int t_gridParams);

	void update(sf::Time& t_deltaTime);
	void render(sf::RenderWindow& t_window, int t_gridParams);

};