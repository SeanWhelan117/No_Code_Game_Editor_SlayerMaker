#include "ToolBar.h"

ToolBar::ToolBar()
{
	loadFiles();

	setupSprites();
}

void ToolBar::loadFiles()
{
	if (!toolBarTexture.loadFromFile("ASSETS\\IMAGES\\toolbar.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading toolbar (toolBarTexture)" << std::endl;
	}

	if (!brushToolTexture.loadFromFile("ASSETS\\IMAGES\\paintTool.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading paintTool (paintTool)" << std::endl;
	}

	if (!fillToolTexture.loadFromFile("ASSETS\\IMAGES\\FillTool.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading FillTool (FillTool)" << std::endl;
	}

}

void ToolBar::setupSprites()
{
	toolBarSprite.setTexture(toolBarTexture);
	brushToolSprite.setTexture(brushToolTexture);
	fillToolSprite.setTexture(fillToolTexture);
}

void ToolBar::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
}

void ToolBar::render(sf::RenderWindow& t_window)
{
	t_window.draw(toolBarSprite);
	t_window.draw(brushToolSprite);
	t_window.draw(fillToolSprite);


}
