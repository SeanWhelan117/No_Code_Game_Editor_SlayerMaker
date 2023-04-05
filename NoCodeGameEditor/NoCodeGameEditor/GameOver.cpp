#include "GameOver.h"

GameOver::GameOver(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
	loadFiles();
	setupButtons();
	setupButtonText();
}

void GameOver::loadFiles()
{
	if (!buttonFont.loadFromFile("./ASSETS/FONTS/NewYork.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}
}

void GameOver::update(sf::Time t_deltaTime)
{
	checkForMousePosAndClick();
}

void GameOver::render(sf::RenderWindow& t_window)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		t_window.draw(buttons[i]);
	}

	t_window.draw(button1Text);
	t_window.draw(button2Text);
}

void GameOver::setupButtons()
{
	//button 0 return to mainmenu, button 1 restart gam
	int xPos = gameWidth / 3;
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		buttons[i].setFillColor(sf::Color::Yellow);
		buttons[i].setSize(sf::Vector2f(500, 250));
		buttons[i].setOrigin(buttons[i].getLocalBounds().width / 2, buttons[i].getLocalBounds().height / 2);
		buttons[i].setPosition(xPos, gameHeight / 2);

		xPos += gameWidth / 3;
	}
}

void GameOver::setupButtonText()
{
	button1Text.setFont(buttonFont);
	button1Text.setFillColor(sf::Color::Black);
	button1Text.setCharacterSize(30u);
	button1Text.setString("Main Menu");
	button1Text.setPosition(buttons[0].getPosition());

	button2Text.setFont(buttonFont);
	button2Text.setFillColor(sf::Color::Black);
	button2Text.setCharacterSize(30u);
	button2Text.setString("Restart Game");
	button2Text.setPosition(buttons[1].getPosition());
}

void GameOver::checkForMousePosAndClick()
{
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		if (buttons[i].getGlobalBounds().contains(mousePos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				buttonPressed = i;
			}
		}
	}
}
