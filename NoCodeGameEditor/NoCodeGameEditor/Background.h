/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Background
{
public:
	/// <summary>
	/// Background Constructor. 
	/// calls loadFiles
	/// Takes in gameWidth and Height as parameters
	/// </summary>
	/// <param name="t_gameWidth"></param>
	/// <param name="t_gameHeight"></param>
	Background(float t_gameWidth, float t_gameHeight);

	/// <summary>
	/// loads the background PNGs and assigns them to textures 
	/// </summary>
	void loadFiles();

	/// <summary>
	/// checks if the passed t_choice is not the same as the currentChoice.
	/// If its not assign it to choice and call setupBackground
	/// </summary>
	/// <param name="t_choice"></param>
	void update(int t_choice);

	/// <summary>
	/// draws the background sprite on the screen.
	/// Takes the sfml window as a parameter 
	/// </summary>
	/// <param name="t_window"></param>
	void render(sf::RenderWindow& t_window);

	/// <summary>
	/// Checks what choice is and sets the texture of the Background sprite based on this
	/// outputs an error message if the choice was not 0, 1 or 2.
	/// sets the scale of the background sprite based on the size of the screen which was loaded in the constructor
	/// </summary>
	/// <param name="t_choice"></param>
	void setupBackground(int t_choice);

private:
	sf::Sprite bgSprite;

	sf::Texture bgTex1;
	sf::Texture bgTex2;
	sf::Texture bgTex3;

	int choice = -99;

	int gameWidth;
	int gameHeight;
};

