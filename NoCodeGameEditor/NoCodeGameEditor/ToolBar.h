/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"

class ToolBar
{
public:
	ToolBar(float t_gameWidth, float t_gameHeight);

	void loadFiles();

	void setupSprites();

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<std::vector<Cell>>& t_grid, int t_gridParams, bool t_choice, int t_choiceNum);

	void render(sf::RenderWindow& t_window);

	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos);

	void resetTools(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeTools(int t_currentTool);

	void setGridCellToMarked(std::vector<std::vector<Cell>>& t_grid, int t_gridParams, sf::Vector2f t_mousePos, std::string t_toolChosen, int t_choiceNum);
	void setToolPosForView(sf::RenderWindow& t_window);
	void pulseTriangles();
	void changeMode(int t_triangleClicked);
	bool wallsPlaced = false;
	bool enemySpawnersPlaced = false;
	bool objectivesPlaced = false;

	bool saved = false;
	
	bool testingGame = false;

	bool brushToolSelected = false;
	bool rubberToolSelected = false;

	sf::Sprite toolBarSprite;

	std::string currentMode = "WALLS";

	int enemyOneSpawnsPlaced = 0;
	int enemyTwoSpawnsPlaced = 0;
	int enemyThreeSpawnsPlaced = 0;

	int coinsPlaced = 0;
	int doorsPlaced = 0;

	static const int MAX_NAV_TRIANGLES = 2;
	sf::Sprite navigationTriangles[MAX_NAV_TRIANGLES];

	bool navigating = false;

	std::map<std::string, int> itemsPlaced;

private:

	sf::Texture toolBarTexture;

	sf::Sprite brushToolSprite;
	sf::Texture brushToolTexture;

	sf::Sprite fillToolSprite;
	sf::Texture fillToolTexture;

	sf::Sprite rubberToolSprite;
	sf::Texture rubberToolTexture;


	float gameWidth = 0;
	float gameHeight = 0;



	sf::RectangleShape addWallsButton;
	sf::RectangleShape saveButton;
	sf::RectangleShape testGameButton;

	sf::RectangleShape addEnemySpawnersButton;


	sf::Vector2f MousePosReal;

	
	sf::Texture navTriangleTexture;

	sf::Vector2f maxScale = sf::Vector2f(1.8, 1.8);
	sf::Vector2f minScale = sf::Vector2f(1.2, 1.2);

	bool scalingUp = true;
	bool scalingDown = false;
	bool pulseTheTriangles = true;



};
