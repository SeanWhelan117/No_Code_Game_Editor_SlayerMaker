/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Animator.h"

class Player
{
public:
	Player(float t_gameWidth, float t_gameHeight, Animator& t_animator);

	void loadFiles();

	void setupPlayer();

	void update(sf::RenderWindow& t_window, bool t_invincibilityActive, bool t_invisibilityActive);

	void render(sf::RenderWindow& t_window);

	sf::Sprite getPlayer();

	void rotatePlayerView();

	std::vector<std::unique_ptr<Bullet >> bulletVector;

	void removeBullet(int t_bulletNum);
private:
	Animator m_animator;
	void playerMovement();
	void move(float t_x, float t_y);
	void shoot(sf::RenderWindow& t_window);

	sf::Vector2f gameSize;

	int speed = 5;
	int speedX = 0;
	int speedY = 0;

	sf::Vector2f position = sf::Vector2f(0, 0);

	sf::Vector2f mousePos;

	const double PI = 3.141592654;

	sf::Clock colourChangeTimer;

	sf::Sprite playerSprite;

	sf::Texture playerIdleTexture;
	sf::Texture playerWalkingTexture;
	sf::Color ogColor;

};

