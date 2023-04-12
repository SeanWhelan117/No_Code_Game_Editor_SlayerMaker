#include "ChoiceBar.h"

ChoiceBar::ChoiceBar(float t_gameWidth, float t_gameHeight) : gameWidth(t_gameWidth), gameHeight(t_gameHeight)
{
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

	//WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS
	//WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS--WALLS

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

	//ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES
	//ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES--ENEMIES
	if (!enemyChoiceTex1.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY1\\Enemy1-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyChoiceTex1 (Enemy1-choice)" << std::endl;
	}

	if (!enemyChoiceTex2.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY2\\Enemy2-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyChoiceTex2 (Enemy2-choice)" << std::endl;
	}

	if (!enemyChoiceTex3.loadFromFile("ASSETS\\IMAGES\\ENEMIES\\ENEMY3\\Enemy3-choice.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading enemyChoiceTex3 (Enemy3-choice)" << std::endl;
	}

	//OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES
	//OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES--OBJECTIVES

	if (!coinTexture.loadFromFile("ASSETS\\IMAGES\\coin.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading coinTexture (coin)" << std::endl;
	}

	if (!doorTexture.loadFromFile("ASSETS\\IMAGES\\door.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading doorTexture (door)" << std::endl;
	}

	if (!monumentTexture.loadFromFile("ASSETS\\IMAGES\\monument.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading monumentTexture (monument)" << std::endl;
	}

	//ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS
	//ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS

	if (!medkitTexture.loadFromFile("ASSETS\\IMAGES\\medkit.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading medkitTexture (medkit)" << std::endl;
	}

	if (!explosiveTexture.loadFromFile("ASSETS\\IMAGES\\dynamite.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading explosiveTexture (dynamite)" << std::endl;
	}

	
	//POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS
	//POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS--POWERUPS

	if (!nukeTexture.loadFromFile("ASSETS\\IMAGES\\nuke.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading nukeTexture (nuke)" << std::endl;
	}

	if (!invincibilityTexture.loadFromFile("ASSETS\\IMAGES\\invincibility.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading invincibilityTexture (invincibility)" << std::endl;
	}

	if (!invisibilityTexture.loadFromFile("ASSETS\\IMAGES\\invisibility.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading invisibility (invisibility)" << std::endl;
	}
}

void ChoiceBar::setupSprites()
{
	choiceBarSprite.setTexture(choiceBarTexture);
	wallChoiceSprite[0].setTexture(wallChoiceTex1);
	wallChoiceSprite[1].setTexture(wallChoiceTex2);
	wallChoiceSprite[2].setTexture(wallChoiceTex3);

	enemyChoiceSprite[0].setTexture(enemyChoiceTex1);
	enemyChoiceSprite[1].setTexture(enemyChoiceTex2);
	enemyChoiceSprite[2].setTexture(enemyChoiceTex3);

	coinSprite.setTexture(coinTexture);
	doorSprite.setTexture(doorTexture);
	monumentSprite.setTexture(monumentTexture);

	medkitSprite.setTexture(medkitTexture);
	explosiveSprite.setTexture(explosiveTexture);
	//gunSprite.setTexture(gunTexture);

	nukeSprite.setTexture(nukeTexture);
	invincibilitySprite.setTexture(invincibilityTexture);
	invisibilitySprite.setTexture(invisibilityTexture);

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

	nukeSprite.setOrigin(nukeSprite.getLocalBounds().width / 2, nukeSprite.getLocalBounds().height / 2);
	nukeSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y - choiceBarSprite.getLocalBounds().height / 3);

	invincibilitySprite.setOrigin(invincibilitySprite.getLocalBounds().width / 2, invincibilitySprite.getLocalBounds().height / 2);
	invincibilitySprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y);

	invisibilitySprite.setOrigin(invisibilitySprite.getLocalBounds().width / 2, invisibilitySprite.getLocalBounds().height / 2);
	invisibilitySprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y + choiceBarSprite.getLocalBounds().height / 3);
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
	else if (currentMode == "POWERUPS")
	{
		t_window.draw(nukeSprite);
		t_window.draw(invincibilitySprite);
		t_window.draw(invisibilitySprite);
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
			//11
		}

		if (currentMode == "POWERUPS")
		{
			processMouseClick(nukeSprite.getGlobalBounds(), t_mousePos, 12);
			processMouseClick(invincibilitySprite.getGlobalBounds(), t_mousePos, 13);
			processMouseClick(invisibilitySprite.getGlobalBounds(), t_mousePos, 14);
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
	else if (currentMode == "POWERUPS")
	{
		switch (t_current)
		{
		case 12:
			nukeSprite.setScale(1, 1);
			break;
		case 13:
			invincibilitySprite.setScale(1, 1);
			break;
		case 14:
			invisibilitySprite.setScale(1, 1);
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
	else if (currentMode == "POWERUPS")
	{
		switch (t_current)
		{
		case 12:
			nukeSprite.setScale(1.3, 1.3);
			break;
		case 13:
			invincibilitySprite.setScale(1.3, 1.3);
			break;
		case 14:
			invisibilitySprite.setScale(1.3, 1.3);
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
			medkitSprite.setPosition(pos4);
			nukeSprite.setPosition(pos4);
		}
		else if (i == 1)
		{
			sf::Vector2f pos5(100, yPos);
			pos5 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos5));
			doorSprite.setPosition(pos5);
			explosiveSprite.setPosition(pos5);
			invincibilitySprite.setPosition(pos5);
		}
		else if (i == 2)
		{
			sf::Vector2f pos6(100, yPos);
			pos6 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos6));
			monumentSprite.setPosition(pos6);
			gunSprite.setPosition(pos6);
			invisibilitySprite.setPosition(pos6);
		}

		yPos += choiceBarSprite.getLocalBounds().height / 3;
	}

}
