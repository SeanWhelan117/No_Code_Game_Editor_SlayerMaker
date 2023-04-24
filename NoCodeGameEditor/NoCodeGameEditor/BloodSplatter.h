#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"


class BloodSplatter
{
public:
	/// <summary>
	/// Blood Splatter constructor.
	/// Calls loadFiles and setupSplatter
	/// takes the blood position and the texture manager as  parameters
	/// </summary>
	/// <param name="t_bloodPos"></param>
	/// <param name="textureManager"></param>
	BloodSplatter(sf::Vector2f t_bloodPos, TextureManager& textureManager);

	/// <summary>
	/// loads the texture of the bloodSplatter using the textureManager.
	/// This means the texture is only loaded from the file once, 
	/// and then applied to each subsequent sprite
	/// </summary>
	void loadFiles();

	/// <summary>
	/// Sets up the blood splatter
	/// sets scale origin, position etc
	/// sets a random rotation of the splatter to make them look slightly different aswell
	/// takes position as a paramater
	/// </summary>
	/// <param name="t_pos"></param>
	void setupSplatter(sf::Vector2f t_pos);

	/// <summary>
	/// changes the blood splatters transparency over time to make it dissapear
	/// draws the sprite to the screen
	/// takes the sfml window as the parameter
	/// </summary>
	/// <param name="t_window"></param>
	void render(sf::RenderWindow& t_window);

	/// <summary>
	/// getter to return the splatterSprite by reference
	/// </summary>
	/// <returns></returns>
	sf::Sprite& getSplatter();

private:

	std::shared_ptr<sf::Texture> bloodSplatterTexture;
	sf::Sprite bloodSplatterSprite;

	TextureManager& m_textureManager;
	sf::Vector2f bloodPos;

};

