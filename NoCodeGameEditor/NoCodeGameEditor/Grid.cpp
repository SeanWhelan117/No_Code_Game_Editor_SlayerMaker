/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#include "Grid.h"

Grid::Grid(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
	setupGrid();
}

void Grid::setupGrid()
{
	sf::Vector2f pos{ 100,100 };
	for (int i = 0; i < MAX_ROWS; i++)
	{
		std::vector<Cell> tempVec;
		theGrid.push_back(tempVec);
	}
	int tempCurrent = 0;
	for (int i = 0; i < MAX_CELLS; i++)
	{
		tempCurrent++;
		int x = i % MAX_ROWS;
		int y = i / MAX_COLS;
		Cell tempCell;
		tempCell.xPos = x;
		tempCell.yPos = y;
		tempCell.initVars();
		tempCell.setPos(pos);
		pos.x += tempCell.getCellShape().getSize().x;
		if (tempCurrent == 30)
		{
			pos.y += tempCell.getCellShape().getSize().y;
			pos.x = 100;
			tempCurrent = 0;
		}
		tempCell.setID(x + (y * MAX_ROWS));
		theGrid.at(x).push_back(tempCell);

	}
}

void Grid::update(sf::Time& t_deltaTime)
{
}

void Grid::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			t_window.draw(theGrid.at(j).at(i).getCellShape());
		}
	}
}