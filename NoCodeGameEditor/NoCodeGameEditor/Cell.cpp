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

void Cell::setMarked()
{
	if (cellShape.getFillColor() == sf::Color::Transparent)
	{
		cellShape.setFillColor(sf::Color::Red);
	}
}

void Cell::setUnmarked()
{
	if (cellShape.getFillColor() == sf::Color::Red)
	{
		cellShape.setFillColor(sf::Color::Transparent);
	}
}

int Cell::getID()
{

	return cellID;
}
