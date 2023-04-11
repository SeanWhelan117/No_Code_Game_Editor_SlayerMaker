/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Medkit
{
public:
	Medkit(sf::Vector2f t_medkitPos, TextureManager& textureManager);

	void loadFiles();

	void setupMedkit();

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getMedkit();

	std::shared_ptr<sf::Texture> medkitTexture;
private:
	TextureManager& m_textureManager;
	sf::Vector2f medkitPos;
	sf::Sprite medkitSprite;
};
