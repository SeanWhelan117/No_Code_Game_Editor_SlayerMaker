#pragma once

class Globals
{
	//unsigned gameWidth = sf::VideoMode::getDesktopMode().width * 0.8;
	//unsigned gameHeight = sf::VideoMode::getDesktopMode().height * 0.8;

public:
	unsigned gameWidth;
	unsigned gameHeight;

	Globals()
	{
		gameWidth = 1500;
		gameHeight = 1500;
	}

};
