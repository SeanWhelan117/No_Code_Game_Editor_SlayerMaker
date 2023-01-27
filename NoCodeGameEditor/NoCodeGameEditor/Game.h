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
#include <vector>

#include "Grid.h"
#include "Cell.h"
#include "Wall.h"
#include "GameState.h"
#include "MainMenu.h"
#include "GameOptions.h"
#include "ToolBar.h"
#include "Player.h"

class Game
{
public:
	unsigned gameWidth = sf::VideoMode::getDesktopMode().width * 0.8;
	unsigned gameHeight = sf::VideoMode::getDesktopMode().height * 0.8;
	Game();
	~Game();

	MainMenu myMenu{ gameWidth, gameHeight };
	GameOptions gameOptions{ gameWidth, gameHeight };
	Grid myGrid{ gameWidth, gameHeight };
	//Wall myWalls;
	GameState myState{ GameState::mainmenu };
	ToolBar myTools{ gameWidth, gameHeight };
	Player myPlayer{ gameWidth, gameHeight };

	sf::View mainView;
	sf::View testView;

	/// <summary>
	/// main method for game
	/// </summary>
	void run();


	void checkMousePos();

	void createWallVector(sf::Vector2f t_wallPos);

	void removeWallVector();

	void viewsCreation();

	bool changeGridSize = false;

	std::vector<Wall> wallVector;
private:

	sf::Vector2i mousePos; // mouses current position

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouseClicks(sf::Event t_event);
	void processTextEntered(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();	

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	bool gridCreated = false;

	int gridSize = 30;

	int numOfWalls = 0;

	bool wallVectorCreated = false;
};

#endif // !GAME_HPP

