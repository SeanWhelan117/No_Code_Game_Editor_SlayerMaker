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

	if (!wallChoiceTex1.loadFromFile("ASSETS\\IMAGES\\WALLS\\wallGrey.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallGrey)" << std::endl;
	}

	if (!wallChoiceTex2.loadFromFile("ASSETS\\IMAGES\\WALLS\\wallBrown.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallBrown)" << std::endl;
	}

	if (!wallChoiceTex3.loadFromFile("ASSETS\\IMAGES\\WALLS\\wallRed.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallRed)" << std::endl;
	}

}

void ChoiceBar::setupSprites()
{
	choiceBarSprite.setTexture(choiceBarTexture);
	choiceBarSprite.setScale(1, 1);
	choiceBarSprite.setOrigin(choiceBarSprite.getLocalBounds().width / 2, choiceBarSprite.getLocalBounds().height / 2);
	choiceBarSprite.setPosition(100, gameHeight / 2);
	std::cout << choiceBarSprite.getPosition().y << std::endl;

	wallChoiceSprite[0].setTexture(wallChoiceTex1);
	wallChoiceSprite[1].setTexture(wallChoiceTex2);
	wallChoiceSprite[2].setTexture(wallChoiceTex3);

	int yPos = choiceBarSprite.getPosition().y - choiceBarSprite.getLocalBounds().height / 3;
	for (int i = 0; i < MAX_WALL_CHOICES; i++)
	{
		wallChoiceSprite[i].scale(3, 3);
		wallChoiceSprite[i].setOrigin(wallChoiceSprite[i].getLocalBounds().width / 2, wallChoiceSprite[i].getLocalBounds().height / 2);
		wallChoiceSprite[i].setPosition(choiceBarSprite.getPosition().x, yPos);
		yPos += choiceBarSprite.getLocalBounds().height / 3;
	}

	
}

void ChoiceBar::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	sf::Vector2f mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));
	checkForMousePosAndClick(t_window, mousePos);
}

void ChoiceBar::render(sf::RenderWindow& t_window)
{
	t_window.draw(choiceBarSprite);
	for (int i = 0; i < MAX_WALL_CHOICES; i++)
	{
		t_window.draw(wallChoiceSprite[i]);
	}
}

void ChoiceBar::checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos)
{
	for (int i = 0; i < MAX_WALL_CHOICES; i++)
	{
		if (wallChoiceSprite[i].getGlobalBounds().contains(t_mousePos))
		{
			changeTools(i);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				currentChoice = i;
				choiceMade = true;
			}
		}
		else
		{
			resetTools(i);
		}
	}
}

void ChoiceBar::resetTools(int t_current)
{
	wallChoiceSprite[t_current].setScale(3, 3);
}

void ChoiceBar::changeTools(int t_current)
{
	wallChoiceSprite[t_current].setScale(4, 4);
}
