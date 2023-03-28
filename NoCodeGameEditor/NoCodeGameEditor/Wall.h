/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "ToolBar.h"
#include "TextureManager.h"


class Wall
{
public:
	Wall(int t_wallTextNum, sf::Vector2f t_wallPos, TextureManager& textureManager);

	void loadFiles();

	void setupWall(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getWall();

	std::shared_ptr<sf::Texture> wallTexture;
	sf::Texture wallTexture2;
	sf::Texture wallTexture3;
	int wallTextureNumber = 0;
private:

	sf::Sprite wallSprite;

	int offset = 15;
	TextureManager& m_textureManager;
	sf::Vector2f wallPos;
};

