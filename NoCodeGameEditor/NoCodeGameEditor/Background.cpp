#include "Background.h"
/// <summary>
/// Background Constructor. 
/// calls loadFiles
/// Takes in gameWidth and Height as parameters
/// </summary>
/// <param name="t_gameWidth"></param>
/// <param name="t_gameHeight"></param>
Background::Background(float t_gameWidth, float t_gameHeight)
{
	loadFiles();

	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
}

/// <summary>
/// loads the background PNGs and assigns them to textures 
/// </summary>
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

/// <summary>
/// checks if the passed t_choice is not the same as the currentChoice.
/// If its not assign it to choice and call setupBackground
/// </summary>
/// <param name="t_choice"></param>
void Background::update(int t_choice)
{
	if (t_choice != choice)
	{
		choice = t_choice;
		setupBackground(choice);
	}
}

/// <summary>
/// draws the background sprite on the screen.
/// Takes the sfml window as a parameter 
/// </summary>
/// <param name="t_window"></param>
void Background::render(sf::RenderWindow& t_window)
{
	t_window.draw(bgSprite);
}

/// <summary>
/// Checks what choice is and sets the texture of the Background sprite based on this
/// outputs an error message if the choice was not 0, 1 or 2.
/// sets the scale of the background sprite based on the size of the screen which was loaded in the constructor
/// </summary>
/// <param name="t_choice"></param>
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
