/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#include "MainMenu.h"

/// <summary>
/// Constructor function for the main menu
/// </summary>
MainMenu::MainMenu(float t_gameWidth, float t_gameHeight)
{
	std::cout << t_gameWidth << t_gameHeight << std::endl;
	int buttonPosX = 100;
	int buttonPosY = t_gameHeight * 0.4; //691
	int startPosY = buttonPosY;

	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		buttons[i].setFillColor(sf::Color(0,0,0,0));
		buttons[i].setSize(sf::Vector2f(525, 125));
		buttonPosY = buttonPosY + 200;
		buttons[i].setPosition(sf::Vector2f(buttonPosX, buttonPosY));
	}

	loadAssets();
	setupButtonText(startPosY);

	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::loadAssets()
{
	if (!m_font.loadFromFile("./ASSETS/FONTS/NewYork.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}

	if (!m_font2.loadFromFile("./ASSETS/FONTS/Another-Danger.ttf"))
	{		
		std::cout << "Error loading font..." << std::endl;
	}


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::update(GameState& t_gameState, sf::RenderWindow& t_window)
{
	mousePos = sf::Mouse::getPosition(t_window);

	//std::cout << "Mouse Position x = " << mousePos.x << " Mouse Position y = " << mousePos.y << std::endl;

	mouseButtonCollision(mousePos, t_gameState);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::render(sf::RenderWindow& t_window)
{

	//drawing buttons
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		t_window.draw(buttons[i]);
	}

	//drawing butttons text
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		t_window.draw(buttonTexts[i]);
	}

	t_window.draw(title);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::setupButtonText(int t_yPos)
{
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		sf::FloatRect textRect = buttonTexts[i].getLocalBounds();
		buttonTexts[i].Bold;
		buttonTexts[i].setFont(m_font);
		buttonTexts[i].setCharacterSize(64u);
		buttonTexts[i].setOrigin(textRect.width / 2, textRect.height / 2);
		buttonTexts[i].setPosition(buttons[i].getPosition().x, buttons[i].getPosition().y);
		buttonTexts[i].setFillColor(sf::Color::Red);
		buttonTexts[i].setString(buttonText[i]);
	}
	sf::FloatRect titleTextRect = title.getLocalBounds();

	title.Bold;
	title.setFont(m_font2);
	title.setCharacterSize(200u);
	title.setOrigin(titleTextRect.width / 2, titleTextRect.height / 2);
	title.setPosition(40,20);
	title.setFillColor(sf::Color::Black);
	title.setString(titleText);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::mouseButtonCollision(sf::Vector2i t_mousePos, GameState& t_gameState)
{
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		sf::FloatRect boundingBox = buttons[i].getGlobalBounds();

		if (boundingBox.contains(static_cast<sf::Vector2f>(t_mousePos)))
		{
			changeButtons(i);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				changeGameState(i, t_gameState);
			}
		}
		else
		{
			resetButtons(i);
		}

	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::resetButtons(int t_current)
{
	buttons[t_current].setFillColor(sf::Color(0, 0, 0, 0));
	buttons[t_current].setScale(1, 1);
	buttonTexts[t_current].setScale(1, 1);
}

void MainMenu::changeButtons(int current_Button)
{
	//buttons[current_Button].setFillColor(sf::Color::Yellow);
	//buttons[current_Button].setScale(1.25, 1.25);
	buttonTexts[current_Button].setScale(1.5, 1.5);
}

void MainMenu::changeGameState(int stateNum, GameState& t_gameState)
{
	if (stateNum == 0)
	{
		t_gameState = GameState::createGame;
	}
	else if (stateNum == 1)
	{
		
	}
	else if (stateNum == 2)
	{
		
	}
	else if (stateNum == 3)
	{
		t_gameState = GameState::exitGame;
	}
}


