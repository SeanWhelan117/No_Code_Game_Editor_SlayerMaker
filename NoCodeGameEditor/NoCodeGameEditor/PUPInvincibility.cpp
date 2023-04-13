#include "PUPInvincibility.h"

PUPInvincibility::PUPInvincibility(sf::Vector2f t_InvincibilityPos, TextureManager& textureManager) : invincibilityPos(t_InvincibilityPos), m_textureManager(textureManager)
{
	loadFiles();
	setupInvincibility();
}

void PUPInvincibility::loadFiles()
{
	invincibilityTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\invincibility.png"));
	invincibilitySprite.setTexture(*invincibilityTexture);
}

void PUPInvincibility::setupInvincibility()
{
	invincibilitySprite.setOrigin(invincibilitySprite.getLocalBounds().width / 2, invincibilitySprite.getLocalBounds().height / 2);
	invincibilitySprite.setPosition(sf::Vector2f(invincibilityPos.x + 15, invincibilityPos.y + 15));
	invincibilitySprite.setScale(0.25, 0.25);
}

void PUPInvincibility::render(sf::RenderWindow& t_window)
{
	t_window.draw(invincibilitySprite);

}

sf::Sprite& PUPInvincibility::getInvincibility()
{
	return invincibilitySprite;
}
