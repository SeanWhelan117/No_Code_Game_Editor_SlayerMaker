/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <map>


class Cell
{
public:
	Cell();
	void setPos(sf::Vector2f t_pos);
	void setupCells();
	void setID(int t_id);
	void setMarked(int t_choiceNum, std::map<std::string, int>& t_itemsPlaced);

	void setUnmarked(std::map<std::string, int>& t_itemsPlaced);

	int getID();

	std::string getType();

	void setType(std::string t_newType);


	int xPos;
	int yPos;
	sf::RectangleShape& getCellShape();

	std::string type = "empty";
	bool filled = false;

private:
	sf::RectangleShape cellShape;
	int cellID;

};