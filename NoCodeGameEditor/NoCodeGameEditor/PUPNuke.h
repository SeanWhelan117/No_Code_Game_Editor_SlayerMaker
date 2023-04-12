/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"


class PUPNuke
{
public:
	PUPNuke(sf::Vector2f t_nukePos, TextureManager& textureManager);

	void loadFiles();

	void setupNuke();

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getNuke();

	std::shared_ptr<sf::Texture> nukeTexture;
private:
	TextureManager& m_textureManager;
	sf::Vector2f nukePos;
	sf::Sprite nukeSprite;
};
