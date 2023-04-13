#include "PUPInvisibility.h"

PUPInvisibility::PUPInvisibility(sf::Vector2f t_invisibilityPos, TextureManager& textureManager) : invisibilityPos(t_invisibilityPos), m_textureManager(textureManager)
{
	loadFiles();
	setupInvisibility();
}

void PUPInvisibility::loadFiles()
{
	invisibilityTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\invisibility.png"));
	invisibilitySprite.setTexture(*invisibilityTexture);
}

void PUPInvisibility::setupInvisibility()
{
	invisibilitySprite.setOrigin(invisibilitySprite.getLocalBounds().width / 2, invisibilitySprite.getLocalBounds().height / 2);
	invisibilitySprite.setPosition(sf::Vector2f(invisibilityPos.x + 15, invisibilityPos.y + 15));
	invisibilitySprite.setScale(0.25, 0.25);
}

void PUPInvisibility::render(sf::RenderWindow& t_window)
{
	t_window.draw(invisibilitySprite);
}

sf::Sprite& PUPInvisibility::getInvisibility()
{
	return invisibilitySprite;
}
