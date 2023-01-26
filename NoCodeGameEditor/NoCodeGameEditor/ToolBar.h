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

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<std::vector<Cell>>& t_grid, int t_gridParams);

	void render(sf::RenderWindow& t_window);

	void checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2i t_mousePos);

	void resetTools(int t_current); //small function which is called to reset buttons after they are not being hoverd over anymore

	void changeTools(int t_currentTool);

	void setGridCellToMarked(std::vector<std::vector<Cell>>& t_grid, int t_gridParams, sf::Vector2i t_mousePos, std::string t_toolChosen);
	bool wallsPlaced = false;

	bool wallPosSaved = false;
	
	bool testingGame = false;

private:

	sf::Sprite toolBarSprite;
	sf::Texture toolBarTexture;

	sf::Sprite brushToolSprite;
	sf::Texture brushToolTexture;

	sf::Sprite fillToolSprite;
	sf::Texture fillToolTexture;

	sf::Sprite rubberToolSprite;
	sf::Texture rubberToolTexture;


	float gameWidth = 0;
	float gameHeight = 0;

	bool brushToolSelected = false;
	bool rubberToolSelected = false;

	sf::RectangleShape addWallsButton;
	sf::RectangleShape saveWallPosButton;
	sf::RectangleShape testGameButton;


};
