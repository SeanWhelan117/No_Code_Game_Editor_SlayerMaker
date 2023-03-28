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

	saveButton.setFillColor(sf::Color::Blue);
	saveButton.setSize(sf::Vector2f(150, 100));
	saveButton.setOrigin(75, 50);
	saveButton.setPosition(gameWidth / 2 + 550, 100);


	testGameButton.setFillColor(sf::Color::Red);
	testGameButton.setSize(sf::Vector2f(150, 100));
	testGameButton.setOrigin(75, 50);
	testGameButton.setPosition(gameWidth / 2 + 750, 100);

	addEnemySpawnersButton.setFillColor(sf::Color::Green);
	addEnemySpawnersButton.setSize(sf::Vector2f(150, 100));
	addEnemySpawnersButton.setOrigin(75, 50);
	addEnemySpawnersButton.setPosition(gameWidth / 2 + 350, 100);

	itemsPlaced = { {"Spawner1", 0}, {"Spawner2", 0}, {"Spawner3", 0}, {"Coins", 0}, {"Doors", 0}};
	//itemsPlaced["Spawner1"] +=400;

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

	if (!navTriangleTexture.loadFromFile("ASSETS\\IMAGES\\triangle.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading triangle (triangle)" << std::endl;
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

	

	for (int i = 0; i < MAX_NAV_TRIANGLES; i++)
	{
		navigationTriangles[i].setTexture(navTriangleTexture);
		navigationTriangles[i].setScale(1.5, 1.5);
		navigationTriangles[i].setOrigin(navigationTriangles[i].getLocalBounds().width / 2, navigationTriangles[i].getLocalBounds().height / 2);

	}
		navigationTriangles[0].setRotation(180);
		navigationTriangles[0].setPosition(125, toolBarSprite.getPosition().y + 25);

		navigationTriangles[1].setRotation(0);
		navigationTriangles[1].setPosition(gameWidth - 125, toolBarSprite.getPosition().y +25);


}

void ToolBar::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<std::vector<Cell>>& t_grid, int t_gridParams, bool t_choice, int t_choiceNum)
{
	setToolPosForView(t_window);

	sf::Vector2i mousePos = sf::Mouse::getPosition(t_window);
	MousePosReal = t_window.mapPixelToCoords(mousePos);
	//std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	//std::cout << mousePos.x << "----" << mousePos.y << std::endl;
	checkForMousePosAndClick(t_window, MousePosReal);

	if (brushToolSelected == true && t_choice == true)
	{
		setGridCellToMarked(t_grid, t_gridParams, MousePosReal, "Brush", t_choiceNum);
	}
	else if (rubberToolSelected == true)
	{
		setGridCellToMarked(t_grid, t_gridParams, MousePosReal, "Rubber", t_choiceNum);
	}

	if (pulseTheTriangles == true)
	{
		pulseTriangles();
	}

}


void ToolBar::render(sf::RenderWindow& t_window)
{
	t_window.draw(toolBarSprite);
	t_window.draw(brushToolSprite);
	t_window.draw(rubberToolSprite);
	t_window.draw(saveButton);

	if (currentMode == "WALLS")
	{
		t_window.draw(addWallsButton);
		t_window.draw(fillToolSprite);
	}
	if (currentMode == "ENEMIES")
	{
		t_window.draw(addEnemySpawnersButton);
	}
	
	t_window.draw(testGameButton);
	
	for (int i = 0; i < MAX_NAV_TRIANGLES; i++)
	{
		t_window.draw(navigationTriangles[i]);
	}
	
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

	if (saveButton.getGlobalBounds().contains(t_mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			saved = true;
		}
	}

	if (testGameButton.getGlobalBounds().contains(t_mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			testingGame = true;
		}
	}

	if (addEnemySpawnersButton.getGlobalBounds().contains(t_mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			enemySpawnersPlaced = true;
		}
	}

	//for (int i = 0; i < MAX_NAV_TRIANGLES; i++)
	//{
	//	if (navigationTriangles[i].getGlobalBounds().contains(t_mousePos))
	//	{
	//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//		{
	//			changeMode(i);
	//		}
	//	}
	//}

	if (navigationTriangles[0].getGlobalBounds().contains(t_mousePos) || navigationTriangles[1].getGlobalBounds().contains(t_mousePos))
	{
		pulseTheTriangles = false;
	}
	else
	{
		pulseTheTriangles = true;
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

void ToolBar::setGridCellToMarked(std::vector<std::vector<Cell>>& t_grid, int t_gridParams, sf::Vector2f t_mousePos, std::string t_toolChosen, int t_choiceNum)
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
						t_grid.at(m).at(i).setMarked(t_choiceNum, itemsPlaced);
					}
					else if (t_toolChosen == "Rubber")
					{
						t_grid.at(m).at(i).setUnmarked(itemsPlaced);
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

	sf::Vector2f pos5(125, 125);
	pos5 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos5));
	navigationTriangles[0].setPosition(pos5);

	sf::Vector2f pos6(gameWidth - 125, 125);
	pos6 = t_window.mapPixelToCoords(static_cast<sf::Vector2i>(pos6));
	navigationTriangles[1].setPosition(pos6);

}

void ToolBar::pulseTriangles()
{
	
	if (scalingUp && navigationTriangles[0].getScale().x < maxScale.x)
	{
		for (int i = 0; i < MAX_NAV_TRIANGLES; i++)
		{
			navigationTriangles[i].setScale(navigationTriangles[i].getScale().x + 0.01, navigationTriangles[i].getScale().y + 0.01);
		}
	}
	else if (scalingDown && navigationTriangles[0].getScale().x > minScale.x)
	{
		for (int i = 0; i < MAX_NAV_TRIANGLES; i++)
		{
			navigationTriangles[i].setScale(navigationTriangles[i].getScale().x - 0.01, navigationTriangles[i].getScale().y - 0.01);
		}
	}

	if (navigationTriangles[0].getScale().x <= minScale.x)
	{
		scalingUp = true;
		scalingDown = false;
	}

	if (navigationTriangles[0].getScale().x >= maxScale.x)
	{
		scalingDown = true;
		scalingUp = false;
	}
}

void ToolBar::changeMode(int t_triangleClicked)
{
	bool set = false;
	if (navigating)
	{
		if (currentMode == "WALLS" && t_triangleClicked == 0)
		{
			// do nothing for now...
		}
		else if (currentMode == "WALLS" && t_triangleClicked == 1)
		{
			currentMode = "ENEMIES";
			std::cout << "1" << std::endl;
			set = true;
		}

		if (currentMode == "ENEMIES" && t_triangleClicked == 0)
		{
			currentMode = "WALLS";
			set = true;
		}
		else if (currentMode == "ENEMIES" && t_triangleClicked == 1 && set == false)
		{
			currentMode = "OBJECTIVES";
			std::cout << "1" << std::endl;
			set = true;
		}

		if (currentMode == "OBJECTIVES" && t_triangleClicked == 0)
		{
			currentMode = "ENEMIES";
			set = true;
		}
		else if (currentMode == "OBJECTIVES" && t_triangleClicked == 1)
		{
			//do nothing for now...
		}
	}
	
}


