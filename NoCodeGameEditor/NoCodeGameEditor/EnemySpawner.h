/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class EnemySpawner
{

public:
	EnemySpawner(int t_spawnerTextNum, sf::Vector2f t_spawnerPos);

	void loadFiles();

	void setupSpawner(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getSpawner();

	sf::Texture spawnerTexture;
	sf::Texture spawnerTexture2;
	sf::Texture spawnerTexture3;
private:

	sf::Sprite spawnerSprite;

	int offset = 15;

	int spawnerTextureNumber = 0;
};

