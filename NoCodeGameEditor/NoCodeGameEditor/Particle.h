/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Particle {
public:
    Particle(float t_x, float t_y, float t_velocityX, float t_velocitY, sf::Time t_lifetime);

    void update(sf::Time t_deltaTime);
    void draw(sf::RenderWindow& t_window) const;

    bool isAlive() const;

private:
    sf::CircleShape particle;
    sf::Vector2f velocity;
    sf::Time lifetime;
    sf::Time currentAge;
};
