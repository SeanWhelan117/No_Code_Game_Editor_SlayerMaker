#include "Monument.h"

Monument::Monument(sf::Vector2f t_monumentPos, TextureManager& textureManager) : monumentPos(t_monumentPos), m_textureManager(textureManager)
{
	loadFiles();
	setupMonument();
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
}

sf::Sprite& Monument::getMonument()
{
	return monumentSprite;
}