/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "PUPNuke.h"
#include "PUPInvincibility.h"
#include "PUPInvisibility.h"


class Powerups
{
public:
	Powerups(TextureManager& textureManager);

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect);

	void render(sf::RenderWindow& t_window);

	std::vector<std::unique_ptr<PUPNuke>> nukeVector;
	std::vector<std::unique_ptr<PUPInvincibility>> invinceVector;
	std::vector<std::unique_ptr<PUPInvisibility>> invisVector;

	void addToVector(sf::Vector2f t_powerupPosition, int t_powerupType);


	bool nukeEnemies = false;
private:

	bool isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2);

	void playerCollision(sf::FloatRect t_playerRect);
	void setupNukeFlash();
	TextureManager& m_textureManager;

	sf::RectangleShape nukeFlash;

	bool flashActive = false;

	sf::Vector2f tempNukeLocation;
};

