/// <summary>
/// @author Sean Whelan
/// @date 2022/23
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
#include <fstream>

#include "TextureManager.h"
#include "Grid.h"
#include "Cell.h"
#include "Wall.h"
#include "GameState.h"
#include "MainMenu.h"
#include "GameOptions.h"
#include "ToolBar.h"
#include "Player.h"
#include "ChoiceBar.h"
#include "Crosshair.h"
#include "Background.h"
#include "EnemySpawner.h"
#include "ChooseGame.h"
#include "BloodSplatter.h"
#include "Objectives.h"
#include "HUD.h"
#include "GameOver.h"
#include "Builder.h"
#include "Items.h"
#include "Powerups.h"

class Game
{
public:
	unsigned gameWidth = sf::VideoMode::getDesktopMode().width * 1;
	unsigned gameHeight = sf::VideoMode::getDesktopMode().height * 1;
	Game();
	~Game();

	TextureManager textureManager;
	MainMenu myMenu{ gameWidth, gameHeight };
	GameOptions gameOptions{ gameWidth, gameHeight };
	Grid myGrid{ gameWidth, gameHeight };
	GameState myState{ GameState::mainmenu };
	ToolBar myTools{ gameWidth, gameHeight };
	Player myPlayer{ gameWidth, gameHeight };
	Crosshair myCrosshair;
	Background myBackground{gameWidth, gameHeight};
	ChooseGame gameChoice{ gameWidth, gameHeight };
	HUD playerHUD{ gameWidth, gameHeight };
	ChoiceBar myChoice{ gameWidth, gameHeight};
	Objectives objectives{ textureManager };
	GameOver gameOver{ gameWidth, gameHeight };
	Builder myBuilder;
	Items items{ textureManager };
	Powerups powerups{ textureManager };


	sf::View mainView;
	sf::View testView;

	/// <summary>
	/// main method for game
	/// </summary>
	void run();


	void checkMousePos();

	Wall createIndividualWall(sf::Vector2f t_wallPos, int t_wallTextNum);

	EnemySpawner createIndividualSpawner(sf::Vector2f t_spawnerPos, int t_spawnerTextNum);

	void removeWallVector();
	void removeEnemySpawnerVector();

	void removeObjectiveVector();

	void viewsCreation();

	void saveDataToCSV();

	void createLevel();

	void clearVectors();

	void collisionDetection();

	BloodSplatter spawnBloodSplatter(sf::Vector2f t_splatterPos);

	bool isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2);

	bool changeGridSize = false;

	std::vector<std::unique_ptr<Wall>> wallVector;
	std::vector<std::unique_ptr<EnemySpawner>> enemySpawnerVector;
	std::vector<std::unique_ptr<BloodSplatter>> bloodSplatterVector;
private:

	sf::Vector2f mousePos; // mouses current position

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouseClicks(sf::Event t_event);
	void processTextEntered(sf::Event t_event);
	void processMouseWheel(sf::Event t_event);
	void processMouseRelease(sf::Event t_event);
	
	
	void update(sf::Time t_deltaTime);
	void render();	

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	bool gridCreated = false;

	int gridSize = 30;

	int numOfWalls = 0;
	int numOfSpawners = 0;
	int numOfCoins = 0;
	int numOfDoors = 0;
	int numOfMonuments = 0;
	int numOfMedkits = 0;
	int numOfExplosives = 0;
	int numOfGuns = 0;
	int numOfNukes = 0;
	int numOfInvinces = 0;
	int numOfInvises = 0;

	bool wallVectorCreated = false;

	bool enemySpawnerVectorCreated = false;

	bool objectiveVectorCreated = false;

	bool itemVectorCreated = false;

	bool powerupVectorCreated = false;

	bool mainViewActive = true;

	bool testViewActive = false;

	double zoomAmount = 1;

	bool zooming = false;
	
	bool scrollingX = false;

	int scrollSpeed = 30;

	int coinsCollected = 0;
	int maxCoins = 0;

	void createWallVector();
	void createSpawnerVector();
	void createObjectives();
	void createItems();

	void createPowerups();

	void checkWallHealth();

	void checkEnemiesEmptied();

};

#endif // !GAME_HPP

