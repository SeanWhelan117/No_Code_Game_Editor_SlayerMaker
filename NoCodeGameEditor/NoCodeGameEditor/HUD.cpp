#include "HUD.h"

HUD::HUD(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
}

void HUD::loadFiles()
{


}

void HUD::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::Vector2f t_playerPos)
{
	myClock.update(t_deltaTime);
	setUIElementsLocations(t_window, t_playerPos);
}

void HUD::render(sf::RenderWindow& t_window)
{
	myClock.render(t_window);
}

void HUD::setUIElementsLocations(sf::RenderWindow& t_window, sf::Vector2f t_playerPos)
{
	sf::Vector2f pos(t_playerPos.x + 250, t_playerPos.y - 250);
	//pos = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos));
	myClock.clockText.setPosition(pos);

}
