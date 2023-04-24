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
	/// <summary>
	/// Cell Constructor, calls setupCells
	/// </summary>
	Cell();

	/// <summary>
	///  sets the position of the cell to the position from parameter
	/// </summary>
	/// <param name="t_pos"></param>
	void setPos(sf::Vector2f t_pos);

	/// <summary>
	/// gives the cells a color, outline and size
	/// </summary>
	void setupCells();

	/// <summary>
	/// sets the ID of the cells
	/// </summary>
	/// <param name="t_id"></param>
	void setID(int t_id);

	/// <summary>
	/// sets the cell to marked. sets the colour based on what is put in.
	/// sets the type to what gameobject needs to be added to that cell
	/// adds to the number of that gameobject that has been placed
	/// takes the choice number for game object and a map of how many of each item has been placed already
	/// as parameters
	/// </summary>
	/// <param name="t_choiceNum"></param>
	/// <param name="t_itemsPlaced"></param>
	void setMarked(int t_choiceNum, std::map<std::string, int>& t_itemsPlaced);

	/// <summary>
	/// checks that the cell has been filled already, in which case, checks which type it is and removes one from the items
	/// placed map 
	/// sets the cell shape back up for being filled by a different game object again
	/// </summary>
	/// <param name="t_itemsPlaced"></param>
	void setUnmarked(std::map<std::string, int>& t_itemsPlaced);

	/// <summary>
	/// returns ID
	/// </summary>
	/// <returns></returns>
	int getID();

	/// <summary>
	/// returns type
	/// </summary>
	/// <returns></returns>
	std::string getType();

	/// <summary>
	/// sets the type
	/// </summary>
	/// <param name="t_newType"></param>
	void setType(std::string t_newType);


	int xPos;
	int yPos;

	/// <summary>
	/// reurns a reference to the cells rectangle shape
	/// </summary>
	/// <returns></returns>
	sf::RectangleShape& getCellShape();

	std::string type = "empty";
	bool filled = false;

private:
	sf::RectangleShape cellShape;
	int cellID;

};