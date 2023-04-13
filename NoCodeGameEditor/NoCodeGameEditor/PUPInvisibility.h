/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class PUPInvisibility
{
public:
	PUPInvisibility(sf::Vector2f t_invisibilityPos, TextureManager& textureManager);

	void loadFiles();

	void setupInvisibility();

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getInvisibility();

	std::shared_ptr<sf::Texture> invisibilityTexture;
private:
	TextureManager& m_textureManager;
	sf::Vector2f invisibilityPos;
	sf::Sprite invisibilitySprite;
};

