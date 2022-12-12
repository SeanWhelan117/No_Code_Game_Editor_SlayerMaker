/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Cell
{
	sf::RectangleShape cellShape;
	int cellID;

public:
	Cell();
	void setPos(sf::Vector2f t_pos);
	void setupCells();
	void setID(int t_id);


	int xPos;
	int yPos;
	sf::RectangleShape& getCellShape();

};