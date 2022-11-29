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
	setupButtonText();
	setupGridSizeBox();
	setupTriangles();
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
}

void GameOptions::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
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
}

void GameOptions::setupButtonText()
{
	sf::FloatRect continueTextRect = continueButtonText.getLocalBounds();

	continueButtonText.Bold;
	continueButtonText.setFont(m_font);
	continueButtonText.setCharacterSize(64u);
	continueButtonText.setOrigin(continueTextRect.width / 2, continueTextRect.height / 2);
	continueButtonText.setPosition(continueButton.getPosition().x, continueButton.getPosition().y);
	continueButtonText.setFillColor(sf::Color::Red);
	continueButtonText.setString(buttonText);



	chooseGridSizeText.Bold;
	chooseGridSizeText.setFont(m_font);
	chooseGridSizeText.setString(chooseGridSize);
	chooseGridSizeText.setCharacterSize(40u);
	gridSizeTextRect = chooseGridSizeText.getLocalBounds();
	chooseGridSizeText.setOrigin(gridSizeTextRect.width / 2, gridSizeTextRect.height / 2);
	chooseGridSizeText.setPosition(gameSize.x / 2, gameSize.y * 0.2);
	chooseGridSizeText.setFillColor(sf::Color::Red);
}

void GameOptions::setupContinueButton()
{
	continueButton.setFillColor(sf::Color(0, 0, 0, 0));
	continueButton.setSize(sf::Vector2f(525, 125));
	continueButton.setPosition(sf::Vector2f(gameSize.x / 2 - (continueButton.getSize().x / 2), gameSize.y * 0.8));
}


void GameOptions::setupGridSizeBox()
{
	gridSizeBox.setSize(sf::Vector2f(180, 65));
	gridSizeBox.setOutlineThickness(5);
	gridSizeBox.setFillColor(sf::Color::White);
	gridSizeBox.setOutlineColor(sf::Color::Black);
	gridSizeBox.setOrigin(gridSizeBox.getSize().x / 2, gridSizeBox.getSize().y / 2);
	gridSizeBox.setPosition(chooseGridSizeText.getPosition().x, chooseGridSizeText.getPosition().y + gridSizeBox.getSize().y + offset);
}

void GameOptions::setupTriangles()
{

	for (int i = 0; i < NUM_OF_TRIANGLES; i++)
	{
		triangles[i].setTexture(triangleTexture);
		triangles[i].setScale(0.5, 0.5);
	}
	triangles[0].setRotation(180);
	triangles[0].setPosition(gridSizeBox.getPosition().x - gridSizeBox.getOrigin().x - (offset * 3), gridSizeBox.getPosition().y  + gridSizeBox.getOrigin().y);


	triangles[1].setPosition(gridSizeBox.getPosition().x + gridSizeBox.getOrigin().x + (offset * 3), gridSizeBox.getPosition().y - gridSizeBox.getOrigin().y - offset);
	
}

