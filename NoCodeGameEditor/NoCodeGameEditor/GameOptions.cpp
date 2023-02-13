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

}

void GameOptions::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, GameState& t_gameState)
{
	mousePos = sf::Mouse::getPosition(t_window);

	//std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	checkForMousePos(t_gameState);

	gameNameText.setString(gameName);
}

void GameOptions::render(sf::RenderWindow& t_window)
{
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

	if(showBGChoices == true)
	{
		for (int i = 0; i < MAX_BG_CHOICES; i++)
		{
			t_window.draw(bgChoiceSprite[i]);
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
	chooseBGRect.setFillColor(sf::Color::Red);
}

void GameOptions::setupBGChoices()
{
	int yPos = gameSize.y * 0.1;

	bgChoiceSprite[0].setTexture(bgChoiceTex1);
	bgChoiceSprite[1].setTexture(bgChoiceTex2);
	bgChoiceSprite[2].setTexture(bgChoiceTex3);

	for (int i = 0; i < MAX_BG_CHOICES; i++)
	{
		bgChoiceSprite[i].scale(0.5, 0.5);
		bgChoiceSprite[i].setOrigin(bgChoiceSprite[i].getLocalBounds().width / 2, bgChoiceSprite[i].getLocalBounds().height / 2);
		bgChoiceSprite[i].setPosition(gameSize.x * 0.85, yPos);
		yPos += gameSize.y * 0.3;
	}
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
		continueButtonText.setScale(1.25, 1.25);
		continueButton.setScale(1.25, 1.25);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			t_gameState = GameState::createGame;
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << "TESTTSS" << std::endl;
			showBGChoices = true;
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
	gameNameRect.setPosition(gameSize.x / 2, gameSize.y / 2);
	
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