#include "HUD.h"

HUD::HUD(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
}

void HUD::loadFiles()
{


}

void HUD::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, sf::Vector2f t_playerPos, bool& t_addHealth, int  t_explosivesCollected, bool t_invincibilityActive)
{
	myClock.update(t_deltaTime);
	myHealthBar.update(t_deltaTime, t_invincibilityActive);
	myExplosiveUI.update(t_deltaTime, t_explosivesCollected);
	setUIElementsLocations(t_window, t_playerPos);

	if (t_addHealth == true)
	{
		t_addHealth = false;
		myHealthBar.plusHealth(50);
	}
}

void HUD::render(sf::RenderWindow& t_window)
{
	myClock.render(t_window);
	myHealthBar.render(t_window);
	myExplosiveUI.render(t_window);
}

void HUD::setUIElementsLocations(sf::RenderWindow& t_window, sf::Vector2f t_playerPos)
{
	sf::Vector2f pos(t_playerPos.x + 250, t_playerPos.y - 250);
	//pos = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos));
	myClock.clockText.setPosition(pos);

	sf::Vector2f pos2(t_playerPos.x, t_playerPos.y - 180);
	myHealthBar.healthBarSprite.setPosition(pos2);

	sf::Vector2f pos3(t_playerPos.x + 20, t_playerPos.y - 210);
	myHealthBar.healthRect.setPosition(pos3);

	sf::Vector2f pos4(t_playerPos.x - 350, t_playerPos.y - 180);
	myExplosiveUI.explosiveUISprite.setPosition(pos4);

}
