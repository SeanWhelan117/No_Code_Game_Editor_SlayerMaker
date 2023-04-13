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

void Monument::update(bool t_invisibilityActive)
{
	monumentHealthBar.setSize(sf::Vector2f(currentMonumentHealth / 5, 10));
	monumentHealthBar.setOrigin(monumentHealthBar.getLocalBounds().width / 2, monumentHealthBar.getLocalBounds().height / 2);
	changeColours();

	if (currentMonumentHealth <= 0)
	{
		std::cout << "GameOver" << std::endl;
		gameOver = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		currentMonumentHealth -= 5;
	}

	if (t_invisibilityActive)
	{
		monumentSprite.setColor(sf::Color(monumentSprite.getColor().r, monumentSprite.getColor().g, monumentSprite.getColor().b, 25));
	}
	else
	{
		monumentSprite.setColor(sf::Color(monumentSprite.getColor().r, monumentSprite.getColor().g, monumentSprite.getColor().b, 255));
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
	monumentHealthBar.setOrigin(monumentHealthBar.getLocalBounds().width / 2, monumentHealthBar.getLocalBounds().height / 2);
	monumentHealthBar.setPosition(monumentSprite.getPosition().x, monumentSprite.getPosition().y - 40);
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

