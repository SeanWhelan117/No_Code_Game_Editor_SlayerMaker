/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#include "MainMenu.h"

/// <summary>
/// Constructor function for the main menu
/// </summary>
MainMenu::MainMenu()
{

	int buttonPosX = 600;//600;
	int buttonPosY = 200;//200;

	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		buttons[i].setFillColor(sf::Color::Green);
		buttons[i].setSize(sf::Vector2f(200, 50));
		buttonPosY = buttonPosY + 120;
		buttons[i].setPosition(sf::Vector2f(buttonPosX, buttonPosY));
	}

	loadAssets();
	setupButtonText();

	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::loadAssets()
{
	if (!m_font.loadFromFile("./ASSETS/FONTS/arial.ttf"))
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

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::setupButtonText()
{
	int buttonYPos = 320;
	int buttonOffset = 120;
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		sf::FloatRect textRect = buttonTexts[i].getLocalBounds();
		buttonTexts[i].Bold;
		buttonTexts[i].setFont(m_font);
		buttonTexts[i].setCharacterSize(32u);
		buttonTexts[i].setOrigin(textRect.width / 2, textRect.height / 2);
		buttonTexts[i].setPosition(buttons[i].getPosition().x, buttonYPos);
		buttonTexts[i].setFillColor(sf::Color::Black);
		buttonTexts[i].setString(buttonText[i]);
		buttonYPos += buttonOffset;
	}

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
	buttons[t_current].setFillColor(sf::Color::Green);
	buttons[t_current].setScale(1, 1);
	buttonTexts[t_current].setScale(1, 1);
}

void MainMenu::changeButtons(int current_Button)
{
	buttons[current_Button].setFillColor(sf::Color::Yellow);
	buttons[current_Button].setScale(1.25, 1.25);
	buttonTexts[current_Button].setScale(1.25, 1.25);
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
	
	}
}


