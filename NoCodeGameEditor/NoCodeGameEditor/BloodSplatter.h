#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"


class BloodSplatter
{
public:
	BloodSplatter(sf::Vector2f t_bloodPos, TextureManager& textureManager);

	void loadFiles();

	void setupSplatter(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getSplatter();

private:

	std::shared_ptr<sf::Texture> bloodSplatterTexture;
	sf::Sprite bloodSplatterSprite;

	TextureManager& m_textureManager;
	sf::Vector2f bloodPos;

};

