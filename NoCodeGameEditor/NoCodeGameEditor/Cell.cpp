/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#include "Cell.h"

Cell::Cell()
{
	setupCells();
}

void Cell::setPos(sf::Vector2f t_pos)
{
	cellShape.setPosition(t_pos);
}

void Cell::setupCells()
{
	cellShape.setFillColor(sf::Color::Transparent);
	cellShape.setOutlineColor(sf::Color::Cyan);
	cellShape.setOutlineThickness(2u);
	cellShape.setSize(sf::Vector2f{ 30,30 });
}

void Cell::setID(int t_id)
{
	cellID = t_id;
}

sf::RectangleShape& Cell::getCellShape()
{
	return cellShape;
}

void Cell::setMarked(int t_choiceNum, int& t_spawnsOne, int& t_spawnsTwo, int& t_spawnsThree)
{
	if (cellShape.getFillColor() == sf::Color::Transparent)
	{
		if (t_choiceNum == 0)
		{
			cellShape.setFillColor(sf::Color::Red); // ----WALLS----
		}
		else if (t_choiceNum == 1)
		{
			cellShape.setFillColor(sf::Color::Green);
		}
		else if (t_choiceNum == 2)
		{
			cellShape.setFillColor(sf::Color::Blue);
		}
		else if (t_choiceNum == 3)
		{
			if (t_spawnsOne < 3)
			{
				cellShape.setFillColor(sf::Color::Magenta); // ----ENEMIES----
				t_spawnsOne++;
			}
		}
		else if (t_choiceNum == 4)
		{
			if (t_spawnsTwo < 3)
			{
				cellShape.setFillColor(sf::Color::Cyan);
				t_spawnsTwo++;
			}
		}
		else if (t_choiceNum == 5)
		{
			if (t_spawnsThree < 3)
			{
				cellShape.setFillColor(sf::Color::Yellow);
				t_spawnsThree++;
			}
		}
	}
}

void Cell::setUnmarked(int& t_spawnsOne, int& t_spawnsTwo, int& t_spawnsThree)
{
	if (cellShape.getFillColor() == sf::Color::Red ||
		cellShape.getFillColor() == sf::Color::Green ||
		cellShape.getFillColor() == sf::Color::Blue)
	{
		cellShape.setFillColor(sf::Color::Transparent);
	}

	if (cellShape.getFillColor() == sf::Color::Magenta)
	{
		t_spawnsOne--;
		cellShape.setFillColor(sf::Color::Transparent);
	}
	else if (cellShape.getFillColor() == sf::Color::Cyan)
	{
		t_spawnsTwo--;
		cellShape.setFillColor(sf::Color::Transparent);
	}
	else if (cellShape.getFillColor() == sf::Color::Yellow)
	{
		t_spawnsThree--;
		cellShape.setFillColor(sf::Color::Transparent);
	}		
}

int Cell::getID()
{

	return cellID;
}
