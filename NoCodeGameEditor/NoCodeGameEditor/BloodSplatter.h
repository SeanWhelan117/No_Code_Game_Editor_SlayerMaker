#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class BloodSplatter
{
public:
	BloodSplatter(sf::Vector2f t_bloodPos, sf::Texture t_bloodTexture);

	void loadFiles();

	void setupSplatter(sf::Vector2f t_pos);

	void render(sf::RenderWindow& t_window);


	sf::Sprite& getSplatter();

	sf::Texture bloodSplatterTexture;
private:

	sf::Sprite bloodSplatterSprite;

};

