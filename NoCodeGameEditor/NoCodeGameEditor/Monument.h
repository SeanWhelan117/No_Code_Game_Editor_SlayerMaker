/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Monument
{

public:
	Monument(sf::Vector2f t_monumentPos, TextureManager& textureManager);

	void loadFiles();

	void setupMonument();

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getMonument();

	std::shared_ptr<sf::Texture> monumentTexture;
private:
	TextureManager& m_textureManager;
	sf::Vector2f monumentPos;
	sf::Sprite monumentSprite;
};

