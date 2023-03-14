/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animator
{
public:
	Animator();

	sf::IntRect animate(sf::Texture t_texture, int t_numOfFrames, int t_frameWidth, int t_frameHeight, int t_cols, int t_rows, int t_time);


private:
	
	int animationFrame = 0;  //number of animation frames in the sprite sheet
	int totalElapsed = 0; //total elapsed is the speed at which you would like the animation to got at
	// higher the total elapsed the more time on each frame

	sf::IntRect rectSourceSprite; //the intrect of the current frame of the spritesheet.
	//This is set to the background sprites texture
};

