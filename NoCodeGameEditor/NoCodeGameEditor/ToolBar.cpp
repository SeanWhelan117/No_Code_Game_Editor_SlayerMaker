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

	saveWallPosButton.setFillColor(sf::Color::Blue);
	saveWallPosButton.setSize(sf::Vector2f(150, 100));
	saveWallPosButton.setOrigin(75, 50);
	saveWallPosButton.setPosition(gameWidth / 2 + 550, 100);


	testGameButton.setFillColor(sf::Color::Red);
	testGameButton.setSize(sf::Vector2f(150, 100));
	testGameButton.setOrigin(75, 50);
	testGameButton.setPosition(gameWidth / 2 + 750, 100);
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

	if (!rubberToolTexture.loadFromFile("ASSETS\\IMAGES\\rubberTool.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading rubberTool (rubberTool)" << std::endl;
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

	rubberToolSprite.setTexture(rubberToolTexture);
	rubberToolSprite.setScale(0.3, 0.3);
	rubberToolSprite.setOrigin(rubberToolSprite.getLocalBounds().width / 2, rubberToolSprite.getLocalBounds().height / 2);
	rubberToolSprite.setPosition(toolBarSprite.getPosition().x - toolBarSprite.getLocalBounds().width / 3, toolBarSprite.getPosition().y);
}

void ToolBar::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<std::vector<Cell>>& t_grid, int t_gridParams)
{
	setToolPosForView(t_window);

	sf::Vector2i mousePos = sf::Mouse::getPosition(t_window);
	MousePosReal = t_window.mapPixelToCoords(mousePos);
	//std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	//std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	checkForMousePosAndClick(t_window, MousePosReal);

	if (brushToolSelected == true)
	{
		setGridCellToMarked(t_grid, t_gridParams, MousePosReal, "Brush");
	}
	else if (rubberToolSelected == true)
	{
		setGridCellToMarked(t_grid, t_gridParams, MousePosReal, "Rubber");
	}

}


void ToolBar::render(sf::RenderWindow& t_window)
{
	t_window.draw(toolBarSprite);
	t_window.draw(brushToolSprite);
	t_window.draw(fillToolSprite);
	t_window.draw(addWallsButton);
	t_window.draw(saveWallPosButton);
	t_window.draw(testGameButton);
	t_window.draw(rubberToolSprite);
	
}

void ToolBar::checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2f t_mousePos)
{
	//1 is rubberTool, 2 is brush tool,  3 is fill tool

	if (rubberToolSprite.getGlobalBounds().contains(t_mousePos))
	{
		changeTools(1);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//brush is selected
			rubberToolSelected = true;
			brushToolSelected = false;
		}
	}
	else
	{
		resetTools(1);
	}

	if (brushToolSprite.getGlobalBounds().contains(t_mousePos))
	{
		changeTools(2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//brush is selected
			brushToolSelected = true;
			rubberToolSelected = false;
		}
	}
	else
	{
		resetTools(2);
	}

	

	if (addWallsButton.getGlobalBounds().contains(t_mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			wallsPlaced = true;
		}
	}

	if (saveWallPosButton.getGlobalBounds().contains(t_mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			wallPosSaved = true;
		}
	}

	if (testGameButton.getGlobalBounds().contains(t_mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			testingGame = true;
		}
	}
}

void ToolBar::changeTools(int t_currentTool)
{
	if (t_currentTool == 1)
	{
		rubberToolSprite.setScale(0.5, 0.5);
	}
	else if (t_currentTool == 2)
	{
		brushToolSprite.setScale(0.5, 0.5);
	}
}

void ToolBar::resetTools(int t_current)
{
	if (t_current == 1)
	{
		rubberToolSprite.setScale(0.3, 0.3);
	}
	else if (t_current == 2)
	{
		brushToolSprite.setScale(0.3, 0.3);
	}
}

void ToolBar::setGridCellToMarked(std::vector<std::vector<Cell>>& t_grid, int t_gridParams, sf::Vector2f t_mousePos, std::string t_toolChosen)
{

	for (int i = 0; i < t_gridParams; i++)
	{
		for (int m = 0; m < t_gridParams; m++)
		{
			if (t_grid.at(m).at(i).getCellShape().getGlobalBounds().contains(t_mousePos))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (t_toolChosen == "Brush")
					{
						t_grid.at(m).at(i).setMarked();
					}
					else if (t_toolChosen == "Rubber")
					{
						t_grid.at(m).at(i).setUnmarked();
					}
				}
				
			}
		}
	}
}

void ToolBar::setToolPosForView(sf::RenderWindow& t_window)
{
	sf::Vector2f pos(gameWidth / 2, 100);
	pos = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos));
	toolBarSprite.setPosition(pos);

	sf::Vector2f pos2(gameWidth / 2, 100);
	pos2 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos2));
	brushToolSprite.setPosition(pos2);

	sf::Vector2f pos3(gameWidth / 2 + toolBarSprite.getLocalBounds().width / 3, 100);
	pos3 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos3));
	fillToolSprite.setPosition(pos3);

	sf::Vector2f pos4(gameWidth / 2 - toolBarSprite.getLocalBounds().width / 3, 100);
	pos4 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos4));
	rubberToolSprite.setPosition(pos4);

}


