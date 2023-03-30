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

	//ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS
	//ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS--ITEMS

	if(!coinTexture.loadFromFile("ASSETS\\IMAGES\\coin.png"))
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

	enemyChoiceSprite[0].setTexture(enemyChoiceTex1);
	enemyChoiceSprite[1].setTexture(enemyChoiceTex2);
	enemyChoiceSprite[2].setTexture(enemyChoiceTex3);

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

	coinSprite.setTexture(coinTexture);
	coinSprite.setOrigin(coinSprite.getLocalBounds().width / 2, coinSprite.getLocalBounds().height / 2);
	coinSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y - choiceBarSprite.getLocalBounds().height / 3);


	doorSprite.setTexture(doorTexture);
	doorSprite.setOrigin(doorSprite.getLocalBounds().width / 2, doorSprite.getLocalBounds().height / 2);
	doorSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y);

	monumentSprite.setTexture(monumentTexture);
	monumentSprite.setOrigin(monumentSprite.getLocalBounds().width / 2, monumentSprite.getLocalBounds().height / 2);
	monumentSprite.setPosition(choiceBarSprite.getPosition().x, choiceBarSprite.getPosition().y + choiceBarSprite.getLocalBounds().height / 3);
	
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
}

void ChoiceBar::checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos)
{
	
		for (int i = 0; i < MAX_CHOICES; i++)
		{
			if (currentMode == "WALLS")
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
			else if (currentMode == "ENEMIES")
			{
				if (enemyChoiceSprite[i].getGlobalBounds().contains(t_mousePos))
				{
					changeTools(i);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						currentChoice = i + 3;
						choiceMade = true;
					}
				}
				else
				{
					resetTools(i);
				}
			}
		}

		if (currentMode == "OBJECTIVES")
		{
			if (chosenGT != 0)
			{
				if (chosenGT == 1)
				{
					if (monumentSprite.getGlobalBounds().contains(t_mousePos))
					{
						changeTools(15);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							currentChoice = 8;
							choiceMade = true;
						}
					}
					else
					{
						resetTools(15);
					}
				}
				else if (chosenGT == 2)
				{
					if (coinSprite.getGlobalBounds().contains(t_mousePos))
					{
						changeTools(5);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							currentChoice = 6;
							choiceMade = true;
						}
					}
					else if (doorSprite.getGlobalBounds().contains(t_mousePos))
					{
						changeTools(10);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							currentChoice = 7;
							choiceMade = true;
						}
					}
					else
					{
						resetTools(15);
					}
				}
			}
			
			
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
		coinSprite.setScale(1, 1);
		doorSprite.setScale(1, 1);
		monumentSprite.setScale(1, 1);
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
		if (t_current == 5)
		{
			coinSprite.setScale(1.3, 1.3);
		}
		else if (t_current == 10)
		{
			doorSprite.setScale(1.3, 1.3);
		}
		else if (t_current == 15)
		{
			monumentSprite.setScale(1.3, 1.3);
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
