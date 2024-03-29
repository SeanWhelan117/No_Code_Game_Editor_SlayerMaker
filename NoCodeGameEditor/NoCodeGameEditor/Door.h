/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Door
{
public:
	Door(sf::Vector2f t_doorPos, TextureManager& textureManager);

	void loadFiles();

	void setupDoor();

	void render(sf::RenderWindow& t_window);

	void doorOpened();

	sf::Sprite& getDoor();

	std::shared_ptr<sf::Texture> doorTexture;

	bool doorAccesible = false;
private:
	TextureManager& m_textureManager;
	sf::Vector2f doorPos;
	sf::Sprite doorSprite;

	sf::Uint8 doorAlpha;
};

