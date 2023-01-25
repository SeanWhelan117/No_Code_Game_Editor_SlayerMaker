#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "ToolBar.h"

class Wall
{
public:
	Wall();

	void loadFiles();

	void setupWall(sf::Vector2f t_pos);

	sf::Sprite& getWall();

	sf::Texture wallTexture;
private:

	sf::Sprite wallSprite;

	int offset = 15;
};

