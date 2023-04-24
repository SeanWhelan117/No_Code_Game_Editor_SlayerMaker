#include "BloodSplatter.h"
/// <summary>
/// Blood Splatter constructor.
/// Calls loadFiles and setupSplatter
/// takes the blood position and the texture manager as  parameters
/// </summary>
/// <param name="t_bloodPos"></param>
/// <param name="textureManager"></param>
BloodSplatter::BloodSplatter(sf::Vector2f t_bloodPos, TextureManager& textureManager) : bloodPos(t_bloodPos), m_textureManager(textureManager)
{
	loadFiles();
	setupSplatter(t_bloodPos);
}

/// <summary>
/// loads the texture of the bloodSplatter using the textureManager.
/// This means the texture is only loaded from the file once, 
/// and then applied to each subsequent sprite
/// </summary>
void BloodSplatter::loadFiles()
{
	bloodSplatterTexture = std::make_shared<sf::Texture>(m_textureManager.getTexture("ASSETS\\IMAGES\\BloodSplatter.png"));
	bloodSplatterSprite.setTexture(*bloodSplatterTexture);
}

/// <summary>
/// Sets up the blood splatter
/// sets scale origin, position etc
/// sets a random rotation of the splatter to make them look slightly different aswell
/// takes position as a paramater
/// </summary>
/// <param name="t_pos"></param>
void BloodSplatter::setupSplatter(sf::Vector2f t_pos)
{
	bloodSplatterSprite.setScale(0.3, 0.3);
	bloodSplatterSprite.setOrigin(bloodSplatterSprite.getGlobalBounds().width / 2, bloodSplatterSprite.getGlobalBounds().height / 2);
	bloodSplatterSprite.setPosition(t_pos.x, t_pos.y);
	int randRotation = rand() % 359;

	bloodSplatterSprite.setRotation(randRotation);
}

/// <summary>
/// changes the blood splatters transparency over time to make it dissapear
/// draws the sprite to the screen
/// takes the sfml window as the parameter
/// </summary>
/// <param name="t_window"></param>
void BloodSplatter::render(sf::RenderWindow& t_window)
{
	bloodSplatterSprite.setColor(sf::Color(bloodSplatterSprite.getColor().r, bloodSplatterSprite.getColor().g, bloodSplatterSprite.getColor().b, bloodSplatterSprite.getColor().a -0.000001));
	t_window.draw(bloodSplatterSprite);
}

/// <summary>
/// getter to return the splatterSprite by reference
/// </summary>
/// <returns></returns>
sf::Sprite& BloodSplatter::getSplatter()
{
	return bloodSplatterSprite;
}
