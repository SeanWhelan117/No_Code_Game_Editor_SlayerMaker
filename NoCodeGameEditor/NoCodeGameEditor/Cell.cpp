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

void Cell::setMarked(int t_choiceNum)
{
	if (cellShape.getFillColor() == sf::Color::Transparent)
	{
		if (t_choiceNum == 0)
		{
			cellShape.setFillColor(sf::Color::Red);
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
			cellShape.setFillColor(sf::Color::Magenta);
		}
		else if (t_choiceNum == 4)
		{
			cellShape.setFillColor(sf::Color::Cyan);

		}
		else if (t_choiceNum == 5)
		{
			cellShape.setFillColor(sf::Color::Yellow);

		}
	}
}

void Cell::setUnmarked()
{
	if (cellShape.getFillColor() == sf::Color::Red ||
		cellShape.getFillColor() == sf::Color::Green ||
		cellShape.getFillColor() == sf::Color::Blue)
	{
		cellShape.setFillColor(sf::Color::Transparent);
	}
}

int Cell::getID()
{

	return cellID;
}
