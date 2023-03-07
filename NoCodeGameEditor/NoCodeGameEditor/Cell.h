/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Cell
{
	

public:
	Cell();
	void setPos(sf::Vector2f t_pos);
	void setupCells();
	void setID(int t_id);
	void setMarked(int t_choiceNum, int& t_spawnsOne, int& t_spawnsTwo, int& t_spawnsThree);

	void setUnmarked(int& t_spawnsOne, int& t_spawnsTwo, int& t_spawnsThree);

	int getID();


	int xPos;
	int yPos;
	sf::RectangleShape& getCellShape();

private:
	sf::RectangleShape cellShape;
	int cellID;

};