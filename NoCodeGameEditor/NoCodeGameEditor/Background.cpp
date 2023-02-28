#include "Background.h"

Background::Background(float t_gameWidth, float t_gameHeight)
{
	loadFiles();

	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
}

void Background::loadFiles()
{
	if (!bgTex1.loadFromFile("ASSETS\\IMAGES\\BACKGROUNDS\\BGGrass.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading bgChoiceTex1 (BGGrass)" << std::endl;
	}

	if (!bgTex2.loadFromFile("ASSETS\\IMAGES\\BACKGROUNDS\\BGSand.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading bgChoiceTex2 (BGSand)" << std::endl;
	}

	if (!bgTex3.loadFromFile("ASSETS\\IMAGES\\BACKGROUNDS\\BGSnow.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading bgChoiceTex3 (BGSnow)" << std::endl;
	}

}

void Background::update(int t_choice)
{
	if (t_choice != choice)
	{
		choice = t_choice;
		setupBackground(choice);
	}
}

void Background::render(sf::RenderWindow& t_window)
{
	t_window.draw(bgSprite);
}

void Background::setupBackground(int t_choice)
{

	if (t_choice == 0)
	{
		bgSprite.setTexture(bgTex1);
	}
	else if (t_choice == 1)
	{
		bgSprite.setTexture(bgTex2);
	}
	else if (t_choice == 2)
	{
		bgSprite.setTexture(bgTex3);
	}
	else
	{
		std::cout << "BG Error" << std::endl;
	}
	
	bgSprite.setScale(1, 1);

	sf::Vector2f currentSize = sf::Vector2f(bgSprite.getGlobalBounds().width, bgSprite.getGlobalBounds().height);
	sf::Vector2f gameSize = sf::Vector2f(gameWidth, gameHeight);

	float scaleX = gameSize.x / currentSize.x;
	float scaleY = gameSize.y / currentSize.y;

	bgSprite.setScale(scaleX, scaleY);

}
