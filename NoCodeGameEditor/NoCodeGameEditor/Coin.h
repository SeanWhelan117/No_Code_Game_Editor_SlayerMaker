/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"


class Coin
{
public:
	Coin(sf::Vector2f t_coinPos, TextureManager& textureManager);

	void loadFiles();

	void setupCoin();

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getCoin();

	std::shared_ptr<sf::Texture> coinTexture;
private:
	TextureManager& m_textureManager;
	sf::Vector2f coinPos;
	sf::Sprite coinSprite;
};

