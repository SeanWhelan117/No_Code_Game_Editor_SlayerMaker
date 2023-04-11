#include "Explosive.h"

Explosive::Explosive(sf::Vector2f t_explosivePos, TextureManager& textureManager) : explosivePos(t_explosivePos), m_textureManager(textureManager)
{
	loadFiles();
	setupExplosive();
}

void Explosive::loadFiles()
{
	explosiveTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\dynamite.png"));
	explosiveSprite.setTexture(*explosiveTexture);
}

void Explosive::setupExplosive()
{
	explosiveSprite.setOrigin(explosiveSprite.getLocalBounds().width / 2, explosiveSprite.getLocalBounds().height / 2);
	explosiveSprite.setPosition(sf::Vector2f(explosivePos.x + 15, explosivePos.y + 15));
	explosiveSprite.setScale(0.25, 0.25);
}

void Explosive::render(sf::RenderWindow& t_window)
{
	t_window.draw(explosiveSprite);
}

sf::Sprite& Explosive::getExplosive()
{
	return explosiveSprite;
}
