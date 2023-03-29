/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#include "GameOptions.h"

GameOptions::GameOptions(float t_gameWidth, float t_gameHeight)
{

	gameSize.x = t_gameWidth;
	gameSize.y = t_gameHeight;
	loadFiles();
	setupContinueButton();
	setupText();
	setupChooseBackgroundRect();
	setupBGChoices();
	setupGridSizeBox();
	setupTriangles();
	setUpGameName();
	setUpGameType();
	setupGTChoices();
	setUpChoiceRectangles();
}

void GameOptions::loadFiles()
{
	if (!m_font.loadFromFile("./ASSETS/FONTS/NewYork.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}

	if (!triangleTexture.loadFromFile("ASSETS\\IMAGES\\triangle.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading triangle (triangle)" << std::endl;
	}

	if (!bgChoiceTex1.loadFromFile("ASSETS\\IMAGES\\BACKGROUNDS\\BGGrass.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading bgChoiceTex1 (BGGrass)" << std::endl;
	}

	if (!bgChoiceTex2.loadFromFile("ASSETS\\IMAGES\\BACKGROUNDS\\BGSand.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading bgChoiceTex2 (BGSand)" << std::endl;
	}

	if (!bgChoiceTex3.loadFromFile("ASSETS\\IMAGES\\BACKGROUNDS\\BGSnow.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading bgChoiceTex3 (BGSnow)" << std::endl;
	}

	if (!gtChoiceTex1.loadFromFile("ASSETS\\IMAGES\\GAMETYPES\\swarmMode.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading gtChoiceTex1 (swarmMode)" << std::endl;
	}

	if (!gtChoiceTex2.loadFromFile("ASSETS\\IMAGES\\GAMETYPES\\ProtectAndServeMode.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading gtChoiceTex2 (ProtectAndServeMode)" << std::endl;
	}

	if (!gtChoiceTex3.loadFromFile("ASSETS\\IMAGES\\GAMETYPES\\CollectAndRunMode.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading gtChoiceTex3 (CollectAndRunMode)" << std::endl;
	}
}

void GameOptions::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, GameState& t_gameState)
{
	mousePos = sf::Mouse::getPosition(t_window);

	//std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	checkForMousePos(t_gameState);

	gameNameText.setString(gameName);

	if (gameName != "" && showBGChoices)
	{
		continueButtonText.setFillColor(sf::Color::Green);
	}
	else
	{
		continueButtonText.setFillColor(sf::Color::Red);
	}
}

void GameOptions::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < 2; i++)
	{
		t_window.draw(choiceRectangles[i]);
	}
	t_window.draw(continueButtonText);
	t_window.draw(chooseGridSizeText);
	

	t_window.draw(gridSizeBox);
	for (int i = 0; i < NUM_OF_TRIANGLES; i++)
	{
		t_window.draw(triangles[i]);
	}
	t_window.draw(currentGridSize);

	t_window.draw(chooseGameNameText);
	t_window.draw(gameNameRect);
	t_window.draw(gameNameText);
	t_window.draw(chooseBGRect);
	t_window.draw(chooseBGText);
	t_window.draw(choiceSquare);
	t_window.draw(choiceSquare2);

	if(showBGChoices)
	{
		for (int i = 0; i < MAX_BG_CHOICES; i++)
		{
			t_window.draw(bgChoiceSprite[i]);
		}
	}

	t_window.draw(gameTypeRect);
	t_window.draw(gameTypeText);

	if (showGameTypeChoices)
	{
		for (int i = 0; i < MAX_GAMETYPE_CHOICES; i++)
		{
			t_window.draw(gameTypeChoiceSprite[i]);
		}
	}

}

void GameOptions::setupText()
{

	continueButtonText.Bold;
	continueButtonText.setFont(m_font);
	continueButtonText.setString(buttonText);
	continueButtonText.setCharacterSize(64u);
	sf::FloatRect continueTextRect = continueButtonText.getLocalBounds();
	continueButtonText.setOrigin(continueTextRect.width / 2, continueTextRect.height / 2);
	continueButtonText.setPosition(continueButton.getPosition().x, continueButton.getPosition().y);
	continueButtonText.setFillColor(sf::Color::Red);



	chooseGridSizeText.Bold;
	chooseGridSizeText.setFont(m_font);
	chooseGridSizeText.setString(chooseGridSize);
	chooseGridSizeText.setCharacterSize(40u);
	gridSizeTextRect = chooseGridSizeText.getLocalBounds();
	chooseGridSizeText.setOrigin(gridSizeTextRect.width / 2, gridSizeTextRect.height / 2);
	chooseGridSizeText.setPosition(gameSize.x / 2, gameSize.y * 0.2);
	chooseGridSizeText.setFillColor(sf::Color::Black);


	chooseBGText.Bold;
	chooseBGText.setFont(m_font);
	chooseBGText.setString(chooseBGString);
	chooseBGText.setCharacterSize(40u);
	chooseBGTextRect = chooseBGText.getLocalBounds();
	chooseBGText.setOrigin(chooseBGTextRect.width / 2, chooseBGTextRect.height / 2);
	chooseBGText.setPosition(gameSize.x / 2, gameSize.y * 0.65);
	chooseBGText.setFillColor(sf::Color::Black);
}

void GameOptions::setupChooseBackgroundRect()
{
	chooseBGRect.setSize(sf::Vector2f(550, 75));
	chooseBGRect.setOrigin(chooseBGRect.getSize().x / 2, chooseBGRect.getSize().y / 2);
	chooseBGRect.setPosition(chooseBGText.getPosition());
	chooseBGRect.setFillColor(sf::Color(0, 0, 0, 0));
}

void GameOptions::setupBGChoices()
{
	int yPos = gameSize.y * 0.2;

	bgChoiceSprite[0].setTexture(bgChoiceTex1);
	bgChoiceSprite[1].setTexture(bgChoiceTex2);
	bgChoiceSprite[2].setTexture(bgChoiceTex3);

	for (int i = 0; i < MAX_BG_CHOICES; i++)
	{
		bgChoiceSprite[i].scale(0.4, 0.4);
		bgChoiceSprite[i].setOrigin(bgChoiceSprite[i].getLocalBounds().width / 2, bgChoiceSprite[i].getLocalBounds().height / 2);
		bgChoiceSprite[i].setPosition(gameSize.x * 0.85, yPos);
		yPos += gameSize.y * 0.28;
	}

	choiceSquare.setSize(sf::Vector2f(bgChoiceSprite[1].getGlobalBounds().width + 15, bgChoiceSprite[1].getGlobalBounds().height + 15));
	choiceSquare.setFillColor(sf::Color::Green);
	choiceSquare.setPosition(-300, -300);
	choiceSquare.setOrigin(choiceSquare.getGlobalBounds().width / 2, choiceSquare.getGlobalBounds().height / 2);

}

void GameOptions::setupContinueButton()
{
	continueButton.setFillColor(sf::Color(0, 0, 0, 0));
	continueButton.setSize(sf::Vector2f(525, 125));
	continueButton.setOrigin(continueButton.getSize().x / 2, continueButton.getSize().y / 2);
	continueButton.setPosition(sf::Vector2f(gameSize.x / 2, gameSize.y * 0.8));
}


void GameOptions::setupGridSizeBox()
{
	gridSizeBox.setSize(sf::Vector2f(180, 65));
	gridSizeBox.setOutlineThickness(5);
	gridSizeBox.setFillColor(sf::Color::White);
	gridSizeBox.setOutlineColor(sf::Color::Black);
	gridSizeBox.setOrigin(gridSizeBox.getSize().x / 2, gridSizeBox.getSize().y / 2);
	gridSizeBox.setPosition(chooseGridSizeText.getPosition().x, chooseGridSizeText.getPosition().y + gridSizeBox.getSize().y + (offset * 2));

	currentGridSize.Bold;
	currentGridSize.setFont(m_font);
	currentGridSize.setString(gridSizeNums[0]);
	currentGridSize.setCharacterSize(32u);
	sf::FloatRect numTextRect = currentGridSize.getLocalBounds();
	currentGridSize.setOrigin(numTextRect.width / 2, numTextRect.height / 2);
	currentGridSize.setPosition(gameSize.x / 2, gridSizeBox.getPosition().y);
	currentGridSize.setFillColor(sf::Color::Black);
}

void GameOptions::setupTriangles()
{

	for (int i = 0; i < NUM_OF_TRIANGLES; i++)
	{
		triangles[i].setTexture(triangleTexture);
		triangles[i].setScale(0.5, 0.5);
	}

	//triangle0 :: left of gridSize
	//triangle1 :: right of gridSize
	triangles[0].setRotation(180);
	triangles[0].setPosition(gridSizeBox.getPosition().x - gridSizeBox.getOrigin().x - (offset * 3), gridSizeBox.getPosition().y  + gridSizeBox.getOrigin().y);

	triangles[1].setPosition(gridSizeBox.getPosition().x + gridSizeBox.getOrigin().x + (offset * 3), gridSizeBox.getPosition().y - gridSizeBox.getOrigin().y - offset);
}

void GameOptions::changeGridSize(int t_triangleNum)
{
	int current = currentGridStringNum;
	int triangleClicked = t_triangleNum;

	if (triangleClicked == 0)
	{
		if (currentGridStringNum != 0)
		{
			currentGridSize.setString(gridSizeNums[currentGridStringNum - 1]);
			currentGridStringNum = currentGridStringNum - 1;
		}
	}
	else if (triangleClicked == 1)
	{
		if (currentGridStringNum < NUM_OF_GRIDSIZES - 1)
		{
			currentGridSize.setString(gridSizeNums[currentGridStringNum + 1]);
			currentGridStringNum = currentGridStringNum + 1;
		}
	}
}

void GameOptions::checkForMousePos(GameState& t_gameState)
{
	if (continueButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
	{
		if (gameName != "" && showBGChoices)
		{
			continueButtonText.setScale(1.25, 1.25);
			continueButton.setScale(1.25, 1.25);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				t_gameState = GameState::createGame;
			}
		}
	}
	else
	{
		continueButtonText.setScale(1, 1);
		continueButton.setScale(1, 1);
	}

	if (gameNameRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			gameNameRect.setFillColor(sf::Color(128, 128, 128, 64));
			canType = true;
		}
	}
	else 
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			gameNameRect.setFillColor(sf::Color::White);
			canType = false;
		}
	}

	if (chooseBGRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
	{
		chooseBGText.setScale(1.2, 1.2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::cout << "TESTTSS" << std::endl;
			showBGChoices = true;
		}
	}
	else
	{
		chooseBGText.setScale(1, 1);
	}

	for (int i = 0; i < MAX_BG_CHOICES; i++)
	{
		if (bgChoiceSprite[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				choiceSquare.setPosition(bgChoiceSprite[i].getPosition());
				chosenBG = i;
			}
		}
	}

	if (gameTypeRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
	{
		gameTypeText.setScale(1.2, 1.2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			showGameTypeChoices = true;
		}
	}
	else
	{
		gameTypeText.setScale(1, 1);
	}

	for (int i = 0; i < MAX_GAMETYPE_CHOICES; i++)
	{
		if (gameTypeChoiceSprite[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && showGameTypeChoices)
			{
				choiceSquare2.setPosition(gameTypeChoiceSprite[i].getPosition().x + 110, gameTypeChoiceSprite[i].getPosition().y - 35);
				chosenGT = i;
			}
		}
	}

}

int GameOptions::getGridSize()
{

	//{ "30 x 30", "40 x 40", "50 x 50", "60 x 60", "70 x 70" };
	int gridNum = 0;

	if (currentGridStringNum == 0)
	{
		gridNum = 30;
	}
	else if (currentGridStringNum == 1)
	{
		gridNum = 40;
	}
	else if (currentGridStringNum == 2)
	{
		gridNum = 50;
	}
	else if (currentGridStringNum == 3)
	{
		gridNum = 60;
	}
	else if (currentGridStringNum == 4)
	{
		gridNum = 70;
	}


	return gridNum;
}

void GameOptions::setUpGameName()
{
	gameNameRect.setSize(sf::Vector2f(350, 65));
	gameNameRect.setOutlineThickness(5);
	gameNameRect.setFillColor(sf::Color::White);
	gameNameRect.setOutlineColor(sf::Color::Black);
	gameNameRect.setOrigin(gameNameRect.getSize().x / 2, gameNameRect.getSize().y / 2);
	gameNameRect.setPosition(gameSize.x / 2, gameSize.y * 0.4);
	
	gameNameText.Bold;
	gameNameText.setFont(m_font);
	gameNameText.setCharacterSize(48u);
	sf::FloatRect gameNameTextRect = currentGridSize.getLocalBounds();
	gameNameText.setOrigin(gameNameTextRect.width / 2, gameNameTextRect.height / 2);
	gameNameText.setPosition(gameNameRect.getPosition().x - 120, gameNameRect.getPosition().y - 10);
	gameNameText.setFillColor(sf::Color::Black);


	chooseGameNameText.Bold;
	chooseGameNameText.setFont(m_font);
	chooseGameNameText.setString(chooseGameName);
	chooseGameNameText.setCharacterSize(40u);

	//chooseGameNameText.setOrigin(chooseGameNameText.width / 2, gridSizeTextRect.height / 2);
	chooseGameNameText.setPosition(gameNameRect.getPosition().x - 300, gameNameRect.getPosition().y - 100);
	chooseGameNameText.setFillColor(sf::Color::Black);
}

void GameOptions::setUpGameType()
{
	gameTypeRect.setSize(sf::Vector2f(550, 75));
	gameTypeRect.setOutlineThickness(5);
	gameTypeRect.setFillColor(sf::Color(0, 0, 0, 0));
	gameTypeRect.setOrigin(gameTypeRect.getSize().x / 2, gameTypeRect.getSize().y / 2);
	gameTypeRect.setPosition(gameSize.x / 2, gameSize.y / 2);


	gameTypeText.Bold;
	gameTypeText.setFont(m_font);
	gameTypeText.setString(chooseGameTypeString);
	gameTypeText.setCharacterSize(40u);
	sf::FloatRect gameTypeTextRect = gameTypeText.getLocalBounds();
	gameTypeText.setOrigin(gameTypeTextRect.width / 2, gameTypeTextRect.height / 2);
	gameTypeText.setPosition(gameTypeRect.getPosition().x, gameTypeRect.getPosition().y);
	gameTypeText.setFillColor(sf::Color::Black);

}

void GameOptions::setupGTChoices()
{
	int yPos = gameSize.y * 0.2;

	gameTypeChoiceSprite[0].setTexture(gtChoiceTex1);
	gameTypeChoiceSprite[1].setTexture(gtChoiceTex2);
	gameTypeChoiceSprite[2].setTexture(gtChoiceTex3);

	for (int i = 0; i < MAX_GAMETYPE_CHOICES; i++)
	{
		gameTypeChoiceSprite[i].scale(1, 1);
		gameTypeChoiceSprite[i].setOrigin(gameTypeChoiceSprite[i].getLocalBounds().width / 2, gameTypeChoiceSprite[i].getLocalBounds().height / 2);
		gameTypeChoiceSprite[i].setPosition(gameSize.x * 0.15, yPos);
		gameTypeChoiceSprite[i].setScale(0.7, 0.7);
		yPos += gameSize.y * 0.28;
	}

	choiceSquare2.setSize(sf::Vector2f(gameTypeChoiceSprite[1].getGlobalBounds().width + 25, gameTypeChoiceSprite[1].getGlobalBounds().height - 50));
	choiceSquare2.setFillColor(sf::Color::Green);
	choiceSquare2.setPosition(-3000, -3000);
	choiceSquare2.setOrigin(choiceSquare.getGlobalBounds().width / 2, choiceSquare.getGlobalBounds().height / 2);
}

void GameOptions::setUpChoiceRectangles()
{
	for (int i = 0; i < 2; i++)
	{
		choiceRectangles[i].setFillColor(sf::Color(81, 81, 81, 150));
		choiceRectangles[i].setSize(sf::Vector2f(1000, gameSize.y));

	}
	choiceRectangles[0].setPosition(0, 0);
	choiceRectangles[1].setPosition(gameSize.x - 1000, 0);
}