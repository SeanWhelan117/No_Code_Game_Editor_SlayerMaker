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

void Cell::setMarked(int t_choiceNum, std::map<std::string, int>& t_itemsPlaced)
{
	//	itemsPlaced = { {"Spawner1", 0}, {"Spawner2", 0}, {"Spawner3", 0}, {"Coins", 0}, {"Doors", 0}};

	if (cellShape.getFillColor() == sf::Color::Transparent && type == "empty")
	{
		if (t_choiceNum == 0)
		{
			cellShape.setFillColor(sf::Color::Red); // ----WALLS----
			type = "wall1";
		}
		else if (t_choiceNum == 1)
		{
			cellShape.setFillColor(sf::Color::Green);
			type = "wall2";

		}
		else if (t_choiceNum == 2)
		{
			cellShape.setFillColor(sf::Color::Blue);
			type = "wall3";

		}
		else if (t_choiceNum == 3)
		{
			if (t_itemsPlaced["Spawner1"] < 3)
			{
				cellShape.setFillColor(sf::Color::Magenta); // ----ENEMIES----
				type = "enemy1";
				t_itemsPlaced["Spawner1"]++;
			}
		}
		else if (t_choiceNum == 4)
		{
			if (t_itemsPlaced["Spawner2"] < 3)
			{
				cellShape.setFillColor(sf::Color::Cyan);
				type = "enemy2";
				t_itemsPlaced["Spawner2"]++;
			}
		}
		else if (t_choiceNum == 5)
		{
			if (t_itemsPlaced["Spawner3"] < 3)
			{
				cellShape.setFillColor(sf::Color::Yellow);
				type = "enemy3";
				t_itemsPlaced["Spawner3"]++;
			}
		}
		else if (t_choiceNum == 6)
		{
			if (t_itemsPlaced["Coins"] < 15)
			{
				cellShape.setFillColor(sf::Color::Black); // ----OBJECTIVES----
				type = "objective1";
				t_itemsPlaced["Coins"]++;
			}
		}
		else if (t_choiceNum == 7)
		{
			if (t_itemsPlaced["Doors"] < 2)
			{
				cellShape.setFillColor(sf::Color::Black);
				type = "objective2";
				t_itemsPlaced["Doors"]++;
			}
		}
	}
}

void Cell::setUnmarked(std::map<std::string, int>& t_itemsPlaced)
{

	//	itemsPlaced = { {"Spawner1", 0}, {"Spawner2", 0}, {"Spawner3", 0}, {"Coins", 0}, {"Doors", 0}};


	//ENEMIES
	if (filled)
	{
		if (type == "enemy1")
		{
			t_itemsPlaced["Spawner1"]-=1;
		}
		else if (type == "enemy2")
		{
			t_itemsPlaced["Spawner2"]-=1;
		}
		else if (type == "enemy3")
		{
			t_itemsPlaced["Spawner3"]-=1;
		}
		else if (type == "objective1")
		{
			t_itemsPlaced["Coins"]-=1;
		}
		else if (type == "objective2")
		{
			t_itemsPlaced["Doors"]-=1;
		}
		cellShape.setFillColor(sf::Color::Transparent);
		filled = false;
		type = "empty";
	}
}

int Cell::getID()
{

	return cellID;
}

std::string Cell::getType()
{
	return type;
}

void Cell::setType(std::string t_newType)
{
	type = t_newType;
}
