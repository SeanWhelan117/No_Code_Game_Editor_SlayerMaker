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
	//setupGrid();
}

void Grid::setupGrid(int t_gridParams)
{
	int maxCells = t_gridParams * t_gridParams;
	int maxCols = t_gridParams;
	int maxRows = t_gridParams;

	sf::Vector2f pos{ 100,100 };
	for (int i = 0; i < maxRows; i++)
	{
		std::vector<Cell> tempVec;
		theGrid.push_back(tempVec);
	}
	int tempCurrent = 0;
	for (int i = 0; i < maxCells; i++)
	{
		tempCurrent++;
		int x = i % maxRows;
		int y = i / maxCols;
		Cell tempCell;
		tempCell.xPos = x;
		tempCell.yPos = y;
		tempCell.initVars();
		tempCell.setPos(pos);
		pos.x += tempCell.getCellShape().getSize().x;
		if (tempCurrent == maxCols)
		{
			pos.y += tempCell.getCellShape().getSize().y;
			pos.x = 100;
			tempCurrent = 0;
		}
		tempCell.setID(x + (y * maxRows));
		theGrid.at(x).push_back(tempCell);

	}
}

void Grid::update(sf::Time& t_deltaTime)
{
}

void Grid::render(sf::RenderWindow& t_window, int t_gridParams)
{
	int maxCols = t_gridParams;
	int maxRows = t_gridParams;

	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			t_window.draw(theGrid.at(j).at(i).getCellShape());
		}
	}
}