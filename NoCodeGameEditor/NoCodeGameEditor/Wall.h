#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "ToolBar.h"

class Wall
{
public:
	Wall(int t_wallTextNum);

	void loadFiles();

	void setupWall(sf::Vector2f t_pos);

	sf::Sprite& getWall();

	sf::Texture wallTexture;
	sf::Texture wallTexture2;
	sf::Texture wallTexture3;
private:

	sf::Sprite wallSprite;

	int offset = 15;

	int wallTextureNumber = 0;
};

