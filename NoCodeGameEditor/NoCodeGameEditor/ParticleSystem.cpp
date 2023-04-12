#include "ParticleSystem.h"

Particle::Particle(float t_x, float t_y, float t_velocityX, float t_velocityY, sf::Time t_lifetime) : particle(1.0f), velocity(t_velocityX, t_velocityY), lifetime(t_lifetime), currentAge(sf::Time::Zero)
{
    particle.setPosition(t_x, t_y);
    particle.setFillColor(sf::Color::Red);
}

void Particle::update(sf::Time t_deltaTime)
{
    particle.move(velocity * t_deltaTime.asSeconds());
    currentAge += t_deltaTime;
}

void Particle::draw(sf::RenderWindow& t_window) const
{
    t_window.draw(particle);
}

bool Particle::isAlive() const
{
    return currentAge < lifetime;
}

ParticleSystem::ParticleSystem()
{
}

void ParticleSystem::addExplosion(float t_xPos, float t_yPos, int t_numParticles)
{
    for (int i = 0; i < t_numParticles; i++) {
        float speed = 50.0f + static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 50.0f;
        float angle = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 2.0f * 3.1415926f;
        float velocityX = speed * std::cos(angle);
        float velocityY = speed * std::sin(angle);
        particlesVector.emplace_back(t_xPos, t_yPos, velocityX, velocityY, sf::seconds(0.8f));
    }
}

void ParticleSystem::update(sf::Time dt)
{
    for (auto& particle : particlesVector) 
    {
        particle.update(dt);
    }
    particlesVector.erase(std::remove_if(particlesVector.begin(), particlesVector.end(), [](const Particle& p) { return !p.isAlive(); }), particlesVector.end());
}

void ParticleSystem::draw(sf::RenderWindow& window) const
{
    for (const auto& particle : particlesVector) 
    {
        particle.draw(window);
    }
}