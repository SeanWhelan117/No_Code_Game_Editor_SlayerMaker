#include "Crosshair.h"

Crosshair::Crosshair()
{

	loadFiles();
	setupCrosshair();
}

void Crosshair::loadFiles()
{

	if (!crosshairTexture.loadFromFile("ASSETS\\IMAGES\\crosshair.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading crosshair (crosshairTexture)" << std::endl;
	}
}

void Crosshair::update(sf::RenderWindow& t_window)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));
	mousePos.x -= 18;
	mousePos.y -= 18;
	crosshair.setPosition(mousePos);
}

void Crosshair::render(sf::RenderWindow& t_window)
{
	t_window.draw(crosshair);
}

void Crosshair::setupCrosshair()
{
	crosshair.setTexture(crosshairTexture);
	crosshair.setScale(0.3, 0.3);
	crosshair.setOrigin(crosshair.getGlobalBounds().width / 2, crosshair.getGlobalBounds().height / 2);
}
