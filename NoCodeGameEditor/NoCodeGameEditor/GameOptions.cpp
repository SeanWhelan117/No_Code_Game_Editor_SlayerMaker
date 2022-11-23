/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#include "GameOptions.h"

GameOptions::GameOptions()
{
	loadFiles();
	setupButtonText();
	setupContinueButton();
}

void GameOptions::loadFiles()
{
	if (!m_font.loadFromFile("./ASSETS/FONTS/NewYork.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}
}

void GameOptions::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
}

void GameOptions::render(sf::RenderWindow& t_window)
{
	t_window.draw(continueButtonText);

}

void GameOptions::setupButtonText()
{
	sf::FloatRect titleTextRect = continueButtonText.getLocalBounds();

	continueButtonText.Bold;
	continueButtonText.setFont(m_font);
	continueButtonText.setCharacterSize(64u);
	continueButtonText.setOrigin(titleTextRect.width / 2, titleTextRect.height / 2);
	continueButtonText.setPosition(continueButton.getPosition().x, continueButton.getPosition().y);
	continueButtonText.setFillColor(sf::Color::Red);
	continueButtonText.setString(buttonText);

}

void GameOptions::setupContinueButton()
{
	continueButton.setFillColor(sf::Color(0, 0, 0, 0));
	continueButton.setSize(sf::Vector2f(525, 125));
	continueButton.setPosition(sf::Vector2f(100,100));
}
