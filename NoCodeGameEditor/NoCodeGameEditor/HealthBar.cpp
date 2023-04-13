#include "HealthBar.h"

HealthBar::HealthBar()
{
	loadFiles();
	setupHealthBarSprite();
	setupHealthRect();
}

void HealthBar::loadFiles()
{
	if (!healthBarTexture.loadFromFile("ASSETS\\IMAGES\\healthbar.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading healthBarTexture (healthbar)" << std::endl;
	}

}

void HealthBar::update(sf::Time t_deltaTime, bool t_invincibilityActive)
{
	healthRect.setSize(sf::Vector2f(currentHealth, 36));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		minusHealth(5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		plusHealth(5);
	}

	if (currentHealth <= 0)
	{
		std::cout << "GameOver" << std::endl;
		gameOver = true;
	}

	if (t_invincibilityActive == true)
	{
		if (colourChangeTimer.getElapsedTime().asMilliseconds() >= 500.0f)
		{
			colourChangeTimer.restart();

			sf::Color colour(std::rand() % 256, std::rand() % 256, std::rand() % 256);
			healthRect.setFillColor(colour);
		}
	}
	else
	{
		healthRect.setFillColor(sf::Color::Red);
	}
}

void HealthBar::render(sf::RenderWindow& t_window)
{
	t_window.draw(healthRect);
	t_window.draw(healthBarSprite);
}

void HealthBar::setupHealthBarSprite()
{
	healthBarSprite.setTexture(healthBarTexture);
	healthBarSprite.setPosition(100, 100);
	healthBarSprite.setOrigin(healthBarSprite.getLocalBounds().width / 2, healthBarSprite.getLocalBounds().height);

}

void HealthBar::setupHealthRect()
{
	healthRect.setFillColor(sf::Color::Red);
	fullHealthBar = healthBarSprite.getGlobalBounds().width - 45;
	currentHealth = fullHealthBar;
	healthRect.setSize(sf::Vector2f(fullHealthBar, 36));
	healthRect.setOrigin(healthRect.getLocalBounds().width / 2, healthRect.getLocalBounds().height / 2);
}

void HealthBar::minusHealth(int t_health)
{
	if (currentHealth - t_health > 0)
	{
		currentHealth -= t_health;
	}
	else
	{
		currentHealth = 0;
	}
}

void HealthBar::plusHealth(int t_health)
{
	if (currentHealth + t_health <= fullHealthBar)
	{
		currentHealth += t_health;
	}
	else
	{
		currentHealth = fullHealthBar;
	}
}
