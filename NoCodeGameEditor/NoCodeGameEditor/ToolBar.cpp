#include "ToolBar.h"

ToolBar::ToolBar(float t_gameWidth, float t_gameHeight)
{
	loadFiles();

	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;

	setupSprites();

	addWallsButton.setFillColor(sf::Color::Green);
	addWallsButton.setSize(sf::Vector2f(150, 100));
	addWallsButton.setOrigin(75, 50);
	addWallsButton.setPosition(gameWidth / 2 + 350, 100);
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
	toolBarSprite.setScale(1, 1);
	toolBarSprite.setOrigin(toolBarSprite.getLocalBounds().width / 2, toolBarSprite.getLocalBounds().height / 2);
	toolBarSprite.setPosition(gameWidth / 2, 100);


	brushToolSprite.setTexture(brushToolTexture);
	brushToolSprite.setScale(0.3, 0.3);
	brushToolSprite.setOrigin(brushToolSprite.getLocalBounds().width / 2, brushToolSprite.getLocalBounds().height / 2);
	brushToolSprite.setPosition(toolBarSprite.getPosition().x, toolBarSprite.getPosition().y);


	fillToolSprite.setTexture(fillToolTexture);
	fillToolSprite.setScale(0.5, 0.5);
	fillToolSprite.setOrigin(fillToolSprite.getLocalBounds().width / 2, fillToolSprite.getLocalBounds().height / 2);
	fillToolSprite.setPosition(toolBarSprite.getPosition().x + toolBarSprite.getLocalBounds().width / 3, toolBarSprite.getPosition().y);
}

void ToolBar::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<std::vector<Cell>>& t_grid, int t_gridParams)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(t_window);

	std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	checkForMousePosAndClick(t_window, mousePos);

	if (brushToolSelected == true)
	{
		setGridCellToMarked(t_grid, t_gridParams, mousePos);
	}

	if (wallsPlaced == true)
	{

	}
}


void ToolBar::render(sf::RenderWindow& t_window)
{
	t_window.draw(toolBarSprite);
	t_window.draw(brushToolSprite);
	t_window.draw(fillToolSprite);
	t_window.draw(addWallsButton);

	


}

void ToolBar::checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2i t_mousePos)
{
	//1 is click and place, 2 is brush tool,  3 is fill tool

	if (brushToolSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(t_mousePos)))
	{
		changeTools(2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//brush is selected
			brushToolSelected = true;
		}
	}
	else
	{
		resetTools(2);
	}

	if (addWallsButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(t_mousePos)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			wallsPlaced == true;
		}
	}
}

void ToolBar::changeTools(int t_currentTool)
{
	if (t_currentTool == 2)
	{
		brushToolSprite.setScale(0.5, 0.5);
	}
}

void ToolBar::resetTools(int t_current)
{
	if (t_current == 2)
	{
		brushToolSprite.setScale(0.3, 0.3);
	}
}

void ToolBar::setGridCellToMarked(std::vector<std::vector<Cell>>& t_grid, int t_gridParams, sf::Vector2i t_mousePos)
{

	for (int i = 0; i < t_gridParams; i++)
	{
		for (int m = 0; m < t_gridParams; m++)
		{
			if (t_grid.at(m).at(i).getCellShape().getGlobalBounds().contains(static_cast<sf::Vector2f>(t_mousePos)))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					t_grid.at(m).at(i).setMarked();
				}
				
			}
		}
	}
}


