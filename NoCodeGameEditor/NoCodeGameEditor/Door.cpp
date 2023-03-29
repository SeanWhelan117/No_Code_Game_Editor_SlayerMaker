#include "Door.h"

Door::Door(sf::Vector2f t_doorPos, TextureManager& textureManager) : doorPos(t_doorPos), m_textureManager(textureManager)
{
	loadFiles();
	setupDoor();
}

void Door::loadFiles()
{
	doorTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\door.png"));
	doorSprite.setTexture(*doorTexture);
}

void Door::setupDoor()
{
	doorSprite.setOrigin(doorSprite.getLocalBounds().width / 2, doorSprite.getLocalBounds().height / 2);
	doorSprite.setPosition(sf::Vector2f(doorPos.x + 15, doorPos.y + 15));
	doorSprite.setScale(0.25, 0.25);

}

void Door::render(sf::RenderWindow& t_window)
{
	t_window.draw(doorSprite);
}

sf::Sprite& Door::getDoor()
{
	return doorSprite;
}

