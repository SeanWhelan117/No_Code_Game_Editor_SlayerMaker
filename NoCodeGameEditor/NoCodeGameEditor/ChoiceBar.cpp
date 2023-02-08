#include "ChoiceBar.h"

ChoiceBar::ChoiceBar(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;

	loadFiles();
	setupSprites();
}

void ChoiceBar::loadFiles()
{
	if (!choiceBarTexture.loadFromFile("ASSETS\\IMAGES\\choicebar.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading toolbar (choicebar.png)" << std::endl;
	}

}

void ChoiceBar::setupSprites()
{
	choiceBarSprite.setTexture(choiceBarTexture);
	choiceBarSprite.setScale(1, 1);
	choiceBarSprite.setOrigin(choiceBarSprite.getLocalBounds().width / 2, choiceBarSprite.getLocalBounds().height / 2);
	choiceBarSprite.setPosition(100, gameHeight / 2);
	std::cout << choiceBarSprite.getPosition().y << std::endl;
}

void ChoiceBar::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	/*sf::Vector2i mousePos = sf::Mouse::getPosition(t_window);
	std::cout << mousePos.x << "--------" << mousePos.y << std::endl;*/
}

void ChoiceBar::render(sf::RenderWindow& t_window)
{
	t_window.draw(choiceBarSprite);
}
