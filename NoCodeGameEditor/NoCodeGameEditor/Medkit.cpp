#include "Medkit.h"

Medkit::Medkit(sf::Vector2f t_medkitPos, TextureManager& textureManager): medkitPos(t_medkitPos), m_textureManager(textureManager)
{
	loadFiles();
	setupMedkit();
}

void Medkit::loadFiles()
{
	medkitTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\medkit.png"));
	medkitSprite.setTexture(*medkitTexture);
}

void Medkit::setupMedkit()
{
	medkitSprite.setOrigin(medkitSprite.getLocalBounds().width / 2, medkitSprite.getLocalBounds().height / 2);
	medkitSprite.setPosition(sf::Vector2f(medkitPos.x + 15, medkitPos.y + 15));
	medkitSprite.setScale(0.25, 0.25);
}

void Medkit::render(sf::RenderWindow& t_window)
{
	t_window.draw(medkitSprite);
}

sf::Sprite& Medkit::getMedkit()
{
	return medkitSprite;
}
