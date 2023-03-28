#include "BloodSplatter.h"

BloodSplatter::BloodSplatter(sf::Vector2f t_bloodPos, TextureManager& textureManager) : bloodPos(t_bloodPos), m_textureManager(textureManager)
{
	loadFiles();
	setupSplatter(t_bloodPos);
}

void BloodSplatter::loadFiles()
{

	bloodSplatterTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\BloodSplatter.png"));
	bloodSplatterSprite.setTexture(*bloodSplatterTexture);
}

void BloodSplatter::setupSplatter(sf::Vector2f t_pos)
{
	bloodSplatterSprite.setScale(0.3, 0.3);
	bloodSplatterSprite.setOrigin(bloodSplatterSprite.getGlobalBounds().width / 2, bloodSplatterSprite.getGlobalBounds().height / 2);
	bloodSplatterSprite.setPosition(t_pos.x, t_pos.y);
	int randRotation = rand() % 359;

	bloodSplatterSprite.setRotation(randRotation);
}

void BloodSplatter::render(sf::RenderWindow& t_window)
{
	t_window.draw(bloodSplatterSprite);
}

sf::Sprite& BloodSplatter::getSplatter()
{
	return bloodSplatterSprite;
}
