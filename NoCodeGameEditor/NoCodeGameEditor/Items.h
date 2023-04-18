/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Medkit.h"
#include "Explosive.h"
#include "ParticleSystem.h"

class Items
{
public: 
	Items(TextureManager& textureManager);

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::FloatRect t_playerRect);

	void render(sf::RenderWindow& t_window);

	std::vector<std::unique_ptr<Medkit>> medkitVector;
	std::vector<std::unique_ptr<Explosive>> explosiveVector;
	//std::vector<std::unique_ptr<Gun>> gunVector;

	std::vector<sf::CircleShape> collisionCircleVector;

	void addToVector(sf::Vector2f t_itemPosition, int t_itemType);

	bool isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2);

	void playerCollision(sf::FloatRect t_playerRect);

	void dropBomb(sf::Vector2f t_playerPos);

	void removeExplosive(int t_remove);

	void spawnExplosion(sf::Vector2f t_explosionPosition);

	bool addHealth = false;
	int explosivesCollected = 0;
private:
	TextureManager& m_textureManager;

	std::vector<ParticleSystem> particleSystemsVector;
};

