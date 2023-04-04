#include "Monument.h"

Monument::Monument(sf::Vector2f t_monumentPos, TextureManager& textureManager) : monumentPos(t_monumentPos), m_textureManager(textureManager)
{
	loadFiles();
	setupMonument();
	setupHealthBar();
}

void Monument::loadFiles()
{
	monumentTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\monument.png"));
	monumentSprite.setTexture(*monumentTexture);
}

void Monument::setupMonument()
{
	monumentSprite.setOrigin(monumentSprite.getLocalBounds().width / 2, monumentSprite.getLocalBounds().height / 2);
	monumentSprite.setPosition(sf::Vector2f(monumentPos.x + 15, monumentPos.y + 15));
	monumentSprite.setScale(0.25, 0.25);

}

void Monument::render(sf::RenderWindow& t_window)
{
	t_window.draw(monumentSprite);
	t_window.draw(monumentHealthBar);
}

void Monument::update()
{
	float healthRatio = currentMonumentHealth / maxMonumentHealth;
	monumentHealthBar.setSize(sf::Vector2f(100 * healthRatio, 10));
	monumentHealthBar.setOrigin((1 - healthRatio) * 100 / 2, 0);

	changeColours();

	if (currentMonumentHealth <= 0)
	{
		std::cout << "GameOver" << std::endl;
	}
}

sf::Sprite& Monument::getMonument()
{
	return monumentSprite;
}

void Monument::setupHealthBar()
{
	monumentHealthBar.setFillColor(sf::Color::Green);
	monumentHealthBar.setOutlineThickness(1);
	monumentHealthBar.setOutlineColor(sf::Color::Black);
	monumentHealthBar.setPosition(monumentSprite.getPosition().x - 40, monumentSprite.getPosition().y - 40);
}

void Monument::damageMonument(int t_damage)
{

	currentMonumentHealth -= t_damage;
}

void Monument::changeColours()
{
	if (currentMonumentHealth <= 300 && currentMonumentHealth > 150 && monumentHealthBar.getFillColor() != sf::Color::Yellow)
	{
		monumentHealthBar.setFillColor(sf::Color::Yellow);
	}
	else if (currentMonumentHealth <= 150 && monumentHealthBar.getFillColor() != sf::Color::Red)
	{
		monumentHealthBar.setFillColor(sf::Color::Red);
	}
}

