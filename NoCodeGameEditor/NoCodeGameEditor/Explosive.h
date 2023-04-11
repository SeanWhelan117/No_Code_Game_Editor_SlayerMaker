/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Explosive
{
public:
	Explosive(sf::Vector2f t_explosivePos, TextureManager& textureManager);

	void loadFiles();

	void setupExplosive();

	void render(sf::RenderWindow& t_window);

	sf::Sprite& getExplosive();

	std::shared_ptr<sf::Texture> explosiveTexture;
private:
	TextureManager& m_textureManager;
	sf::Vector2f explosivePos;
	sf::Sprite explosiveSprite;
};

