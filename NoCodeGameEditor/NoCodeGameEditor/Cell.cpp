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

void Cell::setMarked(int t_choiceNum, int& t_spawnsOne, int& t_spawnsTwo, int& t_spawnsThree, int& t_coinsPlaced, int& t_doorsPlaced)
{
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
			if (t_spawnsOne < 3)
			{
				cellShape.setFillColor(sf::Color::Magenta); // ----ENEMIES----
				type = "enemy1";
				t_spawnsOne++;
			}
		}
		else if (t_choiceNum == 4)
		{
			if (t_spawnsTwo < 3)
			{
				cellShape.setFillColor(sf::Color::Cyan);
				type = "enemy2";
				t_spawnsTwo++;
			}
		}
		else if (t_choiceNum == 5)
		{
			if (t_spawnsThree < 3)
			{
				cellShape.setFillColor(sf::Color::Yellow);
				type = "enemy3";
				t_spawnsThree++;
			}
		}
		else if (t_choiceNum == 6)
		{
			if (t_coinsPlaced < 15)
			{
				cellShape.setFillColor(sf::Color::Black); // ----OBJECTIVES----
				type = "objective1";
				t_coinsPlaced++;
			}
		}
		else if (t_choiceNum == 7)
		{
			if (t_doorsPlaced < 2)
			{
				cellShape.setFillColor(sf::Color::Black);
				type = "objective2";
				t_doorsPlaced++;
			}
		}
	}
}

void Cell::setUnmarked(int& t_spawnsOne, int& t_spawnsTwo, int& t_spawnsThree, int& t_coinsPlaced, int& t_doorsPlaced)
{
	////WALLS
	//if (type == "wall1" || type == "wall2" || type == "wall3")
	//{
	//	cellShape.setFillColor(sf::Color::Transparent);
	//	type = "empty";
	//}


	////ENEMIES
	//if (type == "enemy1")
	//{
	//	t_spawnsOne--;
	//	cellShape.setFillColor(sf::Color::Transparent);
	//	type = "empty";
	//}
	//else if (type == "enemy2")
	//{
	//	t_spawnsTwo--;
	//	cellShape.setFillColor(sf::Color::Transparent);
	//	type = "empty";
	//}
	//else if (type == "enemy3")
	//{
	//	t_spawnsThree--;
	//	cellShape.setFillColor(sf::Color::Transparent);
	//	type = "empty";
	//}		


	if (type == "filled")
	{
		if (cellShape.getFillColor() == sf::Color::Magenta)
		{
			t_spawnsOne--;
		}
		else if (cellShape.getFillColor() == sf::Color::Cyan)
		{
			t_spawnsTwo--;
		}
		else if (cellShape.getFillColor() == sf::Color::Yellow)
		{
			t_spawnsThree--;
		}

		cellShape.setFillColor(sf::Color::Transparent);
		type = "empty";
	}
	else if(type == "wall1" || type == "wall2" || type == "wall3")
	{
		cellShape.setFillColor(sf::Color::Transparent);
		type = "empty";
	}
	else if (type == "enemy1")
	{
		t_spawnsOne--;
		cellShape.setFillColor(sf::Color::Transparent);
		type = "empty";
	}
	else if (type == "enemy2")
	{
		t_spawnsTwo--;
		cellShape.setFillColor(sf::Color::Transparent);
		type = "empty";
	}
	else if (type == "enemy3")
	{
		t_spawnsThree--;
		cellShape.setFillColor(sf::Color::Transparent);
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
