#include "PUPNuke.h"

PUPNuke::PUPNuke(sf::Vector2f t_nukePos, TextureManager& textureManager) : nukePos(t_nukePos), m_textureManager(textureManager)
{
	loadFiles();
	setupNuke();
}

void PUPNuke::loadFiles()
{
	nukeTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\nuke.png"));
	nukeSprite.setTexture(*nukeTexture);
}

void PUPNuke::setupNuke()
{
	nukeSprite.setOrigin(nukeSprite.getLocalBounds().width / 2, nukeSprite.getLocalBounds().height / 2);
	nukeSprite.setPosition(sf::Vector2f(nukePos.x + 15, nukePos.y + 15));
	nukeSprite.setScale(0.25, 0.25);
}

void PUPNuke::render(sf::RenderWindow& t_window)
{
	t_window.draw(nukeSprite);
}

sf::Sprite& PUPNuke::getNuke()
{
	return nukeSprite;
}
