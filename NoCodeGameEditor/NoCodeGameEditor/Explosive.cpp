#include "Explosive.h"

Explosive::Explosive(sf::Vector2f t_explosivePos, TextureManager& textureManager, bool t_primed) : explosivePos(t_explosivePos), m_textureManager(textureManager), primed(t_primed)
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

void Explosive::update(sf::Time t_deltaTime)
{
	if (primed == true && exploded == false)
	{
		flashDynamite();
	}
}

void Explosive::render(sf::RenderWindow& t_window)
{
	t_window.draw(explosiveSprite);
}

sf::Sprite& Explosive::getExplosive()
{
	return explosiveSprite;
}

void Explosive::flashDynamite()
{
	timer++;
	//std::cout << "timer " << timer << std::endl;
	if (timer > 20)
	{
		timer = 0;
		flashCount += 1;
		if (red == false)
		{
			explosiveSprite.setColor(sf::Color(176, 16, 16, 255));
			red = true;
		}
		else if (red == true)
		{
			explosiveSprite.setColor(sf::Color(242, 244, 247, 255));
			red = false;
		}
	}
	if (flashCount > 6)
	{
		exploded = true;
	}
}
