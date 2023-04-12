/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Particle.h"

class ParticleSystem 
{
public:
    ParticleSystem();

    void addExplosion(float t_x, float t_y, int t_numParticles);
    void update(sf::Time dt);
    void draw(sf::RenderWindow& t_window) const;

private:
    std::vector<Particle> particlesVector;
};

