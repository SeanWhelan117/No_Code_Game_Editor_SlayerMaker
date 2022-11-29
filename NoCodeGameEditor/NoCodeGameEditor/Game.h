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
#include "Wall.h"
#include "GameState.h"
#include "MainMenu.h"
#include "GameOptions.h"

class Game
{
public:
	unsigned gameWidth = sf::VideoMode::getDesktopMode().width * 0.8;
	unsigned gameHeight = sf::VideoMode::getDesktopMode().height * 0.8;
	Game();
	~Game();

	Grid myGrid;
	Wall myWalls;
	GameState myState{ GameState::mainmenu };
	MainMenu myMenu{ gameWidth, gameHeight };
	GameOptions gameOptions{ gameWidth, gameHeight };


	/// <summary>
	/// main method for game
	/// </summary>
	void run();



private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();	

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP
