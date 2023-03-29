#include "Coin.h"

Coin::Coin(sf::Vector2f t_coinPos, TextureManager& textureManager) : coinPos(t_coinPos), m_textureManager(textureManager)
{
	loadFiles();
	setupCoin();
}

void Coin::loadFiles()
{
	coinTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\coin.png"));
	coinSprite.setTexture(*coinTexture);
}

void Coin::setupCoin()
{
	coinSprite.setOrigin(coinSprite.getLocalBounds().width / 2, coinSprite.getLocalBounds().height / 2);
	coinSprite.setPosition(sf::Vector2f(coinPos.x + 15, coinPos.y + 15));
	coinSprite.setScale(0.25, 0.25);

}

void Coin::render(sf::RenderWindow& t_window)
{
	t_window.draw(coinSprite);
}

sf::Sprite& Coin::getCoin()
{
	return coinSprite;
}
