#include "ChoiceBar.h"

ChoiceBar::ChoiceBar(float t_gameWidth, float t_gameHeight, TextureManager& textureManager) : gameWidth(t_gameWidth), gameHeight(t_gameHeight), m_textureManager(textureManager)
{
	loadFiles();
	setupSprites();
}

void ChoiceBar::loadFiles()
{

	choiceBarTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\choicebar.png"));
	choiceBarSprite.setTexture(*choiceBarTexture);

	wallChoiceTex1 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\WALLS\\wallGrey.png"));
	wallChoiceTex2 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\WALLS\\wallBrown.png"));
	wallChoiceTex3 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\WALLS\\wallRed.png"));

	wallChoiceSprite[0].setTexture(*wallChoiceTex1);
	wallChoiceSprite[1].setTexture(*wallChoiceTex2);
	wallChoiceSprite[2].setTexture(*wallChoiceTex3);

	enemyChoiceTex1 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy1-choice.png"));
	enemyChoiceTex2 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY2\\Enemy2-choice.png"));
	enemyChoiceTex3 = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\ENEMIES\\ENEMY3\\Enemy3-choice.png"));

	enemyChoiceSprite[0].setTexture(*enemyChoiceTex1);
	enemyChoiceSprite[1].setTexture(*enemyChoiceTex2);
	enemyChoiceSprite[2].setTexture(*enemyChoiceTex3);

	coinTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\coin.png"));
	coinSprite.setTexture(*coinTexture);

	doorTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\door.png"));
	doorSprite.setTexture(*doorTexture);

	monumentTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\monument.png"));
	monumentSprite.setTexture(*monumentTexture);


	medkitTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\medkit.png"));
	medkitSprite.setTexture(*medkitTexture);

	explosiveTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\dynamite.png"));
	explosiveSprite.setTexture(*explosiveTexture);


}

void ChoiceBar::setupSprites()
{
	choiceBarSprite.setScale(1, 1);
	choiceBarSprite.setOrigin(choiceBarSprite.getLocalBounds().width / 2, choiceBarSprite.getLocalBounds().height / 2);
	choiceBarSprite.setPosition(100, gameHeight / 2);
	std::cout << choiceBarSprite.getPosition().y << std::endl;

	

	

	int yPos = choiceBarSprite.getPosition().y - choiceBarSprite.getLocalBounds().height / 3;
	for (int i = 0; i < MAX_CHOICES; i++)
	{
		wallChoiceSprite[i].scale(3, 3);
		wallChoiceSprite[i].setOrigin(wallChoiceSprite[i].getLocalBounds().width / 2, wallChoiceSprite[i].getLocalBounds().height / 2);
		wallChoiceSprite[i].setPosition(choiceBarSprite.getPosition().x, yPos);

		enemyChoiceSprite[i].scale(3, 3);
		enemyChoiceSprite[i].setOrigin(enemyChoiceSprite[i].getLocalBounds().width / 2, enemyChoiceSprite[i].getLocalBounds().height / 2);
		enemyChoiceSprite[i].setPosition(choiceBarSprite.getPosition().x, yPos);
		
		
		yPos += choiceBarSprite.getLocalBounds().height / 3;
	}

	coinSprite.setOrigin(coinSprite.getLocalBounds().width / 2, coinSprite.getLocalBounds().height / 2);
	coinSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y - choiceBarSprite.getLocalBounds().height / 3);


	doorSprite.setOrigin(doorSprite.getLocalBounds().width / 2, doorSprite.getLocalBounds().height / 2);
	doorSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y);

	monumentSprite.setOrigin(monumentSprite.getLocalBounds().width / 2, monumentSprite.getLocalBounds().height / 2);
	monumentSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y + choiceBarSprite.getLocalBounds().height / 3);
	
	medkitSprite.setOrigin(medkitSprite.getLocalBounds().width / 2, medkitSprite.getLocalBounds().height / 2);
	medkitSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y - choiceBarSprite.getLocalBounds().height / 3);
	
	explosiveSprite.setOrigin(explosiveSprite.getLocalBounds().width / 2, explosiveSprite.getLocalBounds().height / 2);
	explosiveSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y);
}

void ChoiceBar::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::string t_currentMode, int t_chosenGameType)
{
	if (chosenGT != t_chosenGameType)
	{
		chosenGT = t_chosenGameType;
	}

	setToolPosForView(t_window);
	currentMode = t_currentMode;

	sf::Vector2f mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));
	checkForMousePosAndClick(t_window, mousePos);
}

void ChoiceBar::render(sf::RenderWindow& t_window)
{
	
	t_window.draw(choiceBarSprite);


	if (currentMode == "WALLS")
	{
		for (int i = 0; i < MAX_CHOICES; i++)
		{
			t_window.draw(wallChoiceSprite[i]);
		}
	}
	else if (currentMode == "ENEMIES")
	{
		for (int i = 0; i < MAX_CHOICES; i++)
		{
			t_window.draw(enemyChoiceSprite[i]);
		}
	}
	else if (currentMode == "OBJECTIVES")
	{
		if (chosenGT != 0)
		{
			if (chosenGT == 1)
			{
				t_window.draw(monumentSprite);
			}
			else if (chosenGT == 2)
			{
				t_window.draw(coinSprite);
				t_window.draw(doorSprite);
			}
		}
	}
	else if (currentMode == "ITEMS")
	{
		t_window.draw(medkitSprite);
		t_window.draw(explosiveSprite);
	}
}

void ChoiceBar::checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos)
{
	
		for (int i = 0; i < MAX_CHOICES; i++)
		{
			if (currentMode == "WALLS")
			{
				processMouseClick(wallChoiceSprite[i].getGlobalBounds(), t_mousePos, i);
				
			}
			else if (currentMode == "ENEMIES")
			{
				processMouseClick(enemyChoiceSprite[i].getGlobalBounds(), t_mousePos, i);
			}
		}

		if (currentMode == "OBJECTIVES")
		{
			if (chosenGT != 0)
			{
				if (chosenGT == 1)
				{
					processMouseClick(monumentSprite.getGlobalBounds(), t_mousePos, 8);
				}
				else if (chosenGT == 2)
				{
					processMouseClick(coinSprite.getGlobalBounds(), t_mousePos, 6);
					processMouseClick(doorSprite.getGlobalBounds(), t_mousePos, 7);
				}
			}
		}

		if (currentMode == "ITEMS")
		{
			processMouseClick(medkitSprite.getGlobalBounds(), t_mousePos, 9);
			processMouseClick(explosiveSprite.getGlobalBounds(), t_mousePos, 10);
		}
}

void ChoiceBar::processMouseClick(sf::FloatRect t_object, sf::Vector2f t_mousePos, int t_numLoops)
{
	if (t_object.contains(t_mousePos))
	{
		changeTools(t_numLoops);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (currentMode == "ENEMIES")
			{
				currentChoice = t_numLoops + 3;

			}
			else
			{
				currentChoice = t_numLoops;
			}
			choiceMade = true;
		}
	}
	else
	{
		resetTools(t_numLoops);
	}
}

void ChoiceBar::resetTools(int t_current)
{
	if (currentMode == "WALLS")
	{
		wallChoiceSprite[t_current].setScale(3, 3);

	}
	else if (currentMode == "ENEMIES")
	{
		enemyChoiceSprite[t_current].setScale(3, 3);

	}
	else if (currentMode == "OBJECTIVES")
	{
		switch (t_current)
		{
		case 6:
			coinSprite.setScale(1, 1);
			break;
		case 7:
			doorSprite.setScale(1, 1);
			break;
		case 8:
			monumentSprite.setScale(1, 1);
			break;
		}
	}
	else if (currentMode == "ITEMS")
	{
		switch (t_current)
		{
		case 9:
			medkitSprite.setScale(1, 1);
			break;
		case 10:
			explosiveSprite.setScale(1, 1);
			break;
		case 11:
			std::cout << "Yaknow" << std::endl;
			break;
		}
	}
}

void ChoiceBar::changeTools(int t_current)
{
	if (currentMode == "WALLS")
	{
		wallChoiceSprite[t_current].setScale(4, 4);

	}
	else if (currentMode == "ENEMIES")
	{
		enemyChoiceSprite[t_current].setScale(4, 4);

	}
	else if (currentMode == "OBJECTIVES")
	{
		switch (t_current)
		{
		case 6:
			coinSprite.setScale(1.3, 1.3);
			break;
		case 7:
			doorSprite.setScale(1.3, 1.3);
			break;
		case 8:
			monumentSprite.setScale(1.3, 1.3);
			break;
		}
	}
	else if (currentMode == "ITEMS")
	{
		switch (t_current)
		{
		case 9:
			medkitSprite.setScale(1.3, 1.3);
			break;
		case 10:
			explosiveSprite.setScale(1.3, 1.3);
			break;
		case 11:
			std::cout << "Yaknow" << std::endl;
			break;
		}
	}
}

void ChoiceBar::setToolPosForView(sf::RenderWindow& t_window)
{
	sf::Vector2f pos(100, gameHeight / 2);
	pos = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos));
	choiceBarSprite.setPosition(pos);

	int yPos = gameHeight / 2 - choiceBarSprite.getLocalBounds().height / 3;
	for (int i = 0; i < MAX_CHOICES; i++)
	{

		sf::Vector2f pos2(100, yPos);
		pos2 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos2));
		wallChoiceSprite[i].setPosition(pos2);

		sf::Vector2f pos3(100, yPos);
		pos3 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos3));
		enemyChoiceSprite[i].setPosition(pos3);
		if (i == 0)
		{
			sf::Vector2f pos4(100, yPos);
			pos4 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos4));
			coinSprite.setPosition(pos4);
		}
		else if (i == 1)
		{
			sf::Vector2f pos5(100, yPos);
			pos5 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos5));
			doorSprite.setPosition(pos5);
		}
		else if (i == 2)
		{
			sf::Vector2f pos6(100, yPos);
			pos6 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos6));
			monumentSprite.setPosition(pos6);
		}

		yPos += choiceBarSprite.getLocalBounds().height / 3;
	}

}
