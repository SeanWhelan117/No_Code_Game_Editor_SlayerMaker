#include "Wall.h"

Wall::Wall()
{
	loadFiles();

		wallSprite.setTexture(wallTexture);
		wallSprite.setOrigin(wallSprite.getGlobalBounds().width / 2, wallSprite.getGlobalBounds().height / 2);
}

void Wall::loadFiles()
{
	if (!wallTexture.loadFromFile("ASSETS\\IMAGES\\wallTest.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wall (wallTest)" << std::endl;
	}
}

void Wall::update(sf::Time t_deltaTime, sf::RenderWindow& t_window, std::vector<std::vector<Cell>>& t_grid, int t_gridParams, bool t_wallsPlaced)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(t_window);
	//checkForMousePosAndClick(t_window, mousePos);

	/*if (isClicked == true)
	{
		wallSprites[pickedWall].setPosition(mousePos.x, mousePos.y);

		checkForPlacement(t_grid, t_gridParams);
	}

	if (t_wallsPlaced == true)
	{
		placeWallsOnGrid(t_grid, t_gridParams);
	}*/
}

void Wall::render(sf::RenderWindow& t_window)
{
	//t_window.draw(wallSprite);
}

//void Wall::checkForMousePosAndClick(sf::RenderWindow& t_window, sf::Vector2i t_mousePos)
//{
//	//std::cout << mousePos.x << mousePos.y << std::endl;
//	for (int i = 0; i < 100; i++)
//	{
//		if (wallSprites[i].getGlobalBounds().contains(t_mousePos.x, t_mousePos.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//		{
//			isClicked = true;
//			pickedWall = i;
//		}
//	}
//
//}
//
//void Wall::checkForPlacement(std::vector<std::vector<Cell>>& t_grid, int t_gridParams)
//{
//	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
//	{
//		isClicked = false;
//		snapWallPositionToGrid(t_grid, t_gridParams);
//	}
//}
//
//void Wall::snapWallPositionToGrid(std::vector<std::vector<Cell>>& t_grid, int t_gridParams)
//{
//
//	for (int i = 0; i < t_gridParams; i++)
//	{
//		for (int m = 0; m < t_gridParams; m++)
//		{
//			if (t_grid.at(m).at(i).getCellShape().getGlobalBounds().contains(wallSprites[pickedWall].getPosition()))
//			{
//				sf::Vector2f currentCellPos = t_grid.at(m).at(i).getCellShape().getPosition();
//
//				currentCellPos = sf::Vector2f(currentCellPos.x + offset, currentCellPos.y + offset);
//
//				wallSprites[pickedWall].setPosition(currentCellPos);
//			}
//		}
//	}
//
//	
//}
//
//void Wall::placeWallsOnGrid(std::vector<std::vector<Cell>>& t_grid, int t_gridParams)
//{
//	int wallTemp = 0;
//
//	for (int i = 0; i < t_gridParams; i++)
//	{
//		for (int m = 0; m < t_gridParams; m++)
//		{
//			if (t_grid.at(m).at(i).getCellShape().getFillColor() == sf::Color::Red)
//			{
//				sf::Vector2f currentCellPos = t_grid.at(m).at(i).getCellShape().getPosition();
//				currentCellPos = sf::Vector2f(currentCellPos.x + offset, currentCellPos.y + offset);
//				wallSprites[wallTemp].setPosition(currentCellPos);
//				wallTemp++;
//			}
//		}
//	}
//}
