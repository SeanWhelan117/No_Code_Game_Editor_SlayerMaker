/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Cell.h"
#include "Globals.h"
#include "Wall.h"

class Game
{
public:
	Game();
	~Game();

	Grid myGrid;
	Globals globals;
	Wall myWalls[100];

	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	//unsigned gameWidth = sf::VideoMode::getDesktopMode().width * 0.8;
	//unsigned gameHeight = sf::VideoMode::getDesktopMode().height * 0.8;

	/*unsigned gameWidth = 2000;
	unsigned gameHeight = 2000;*/

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

