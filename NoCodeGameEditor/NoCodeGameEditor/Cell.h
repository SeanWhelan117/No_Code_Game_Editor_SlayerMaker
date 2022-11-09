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

	int ID = 0;
	bool markedBool = false;
	bool startPointSquare = false;
	bool endPointSquare = false;

	sf::Vector2f m_pos;
public:
	sf::RectangleShape cellRect;
	//bool getEndPoint();
	void setEndPoint(bool t_endPointSet);
	void setStartPoint(bool t_startPointSet);

	//bool getStartPoint();
	//bool getMarked();
	void setMarked(bool t_marked);

	void setStartColour();
	void setEndColour();

	int getID();


	void setID(int t_id);

	void setPos(sf::Vector2f t_position);

	sf::RectangleShape getCellRect();
	void setupCellRect();



	int xPos;
	int yPos;


	std::vector<Cell*> m_neighbour;
	void setNeighbours(Cell* t_neighbour);

	sf::Vector2f& getPos();


	float gridSize = 1500.0f;

};