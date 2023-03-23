#include "BloodSplatter.h"

BloodSplatter::BloodSplatter(sf::Vector2f t_bloodPos, sf::Texture t_bloodTexture)
{
	bloodSplatterTexture = t_bloodTexture;
	loadFiles();
	setupSplatter(t_bloodPos);
}

void BloodSplatter::loadFiles()
{
	//if (!bloodSplatterTexture.loadFromFile("ASSETS\\IMAGES\\BloodSplatter.png"))
	//{
	//	// simple error message if previous call fails
	//	std::cout << "problem loading BloodSplatter (BloodSplatter.png)" << std::endl;
	//}
}

void BloodSplatter::setupSplatter(sf::Vector2f t_pos)
{
	bloodSplatterSprite.setTexture(bloodSplatterTexture);
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
