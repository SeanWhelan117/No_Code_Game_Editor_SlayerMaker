/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class PUPInvincibility
{
public:
	PUPInvincibility(sf::Vector2f t_InvincibilityPos, TextureManager& textureManager);

	void loadFiles();

	void setupInvincibility();

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getInvincibility();

	std::shared_ptr<sf::Texture> invincibilityTexture;
private:
	TextureManager& m_textureManager;
	sf::Vector2f invincibilityPos;
	sf::Sprite invincibilitySprite;
};

