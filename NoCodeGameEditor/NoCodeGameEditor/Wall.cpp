#include "Wall.h"

Wall::Wall()
{
	loadFiles();
	for (int i = 0; i < MAX_WALLS; i++)
	{
		wallSprites[i].setPosition(-200, -200);
		wallSprites[i].setTexture(wallTexture);
		wallSprites[i].setOrigin(wallSprites[i].getGlobalBounds().width / 2, wallSprites[i].getGlobalBounds().height / 2);
	}
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

	if (t_wallsPlaced == true)
	{
		placeWallsOnGrid(t_grid, t_gridParams);
	}

	checkForMousePosAndClick(mousePos, t_gridParams, t_grid);
}

void Wall::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MAX_WALLS; i++)
	{
		t_window.draw(wallSprites[i]);
	}
}

void Wall::placeWallsOnGrid(std::vector<std::vector<Cell>>& t_grid, int t_gridParams)
{
	for (int i = 0; i < t_gridParams; i++)
	{
		for (int m = 0; m < t_gridParams; m++)
		{
			if (t_grid.at(m).at(i).getCellShape().getFillColor() == sf::Color::Red)
			{
				sf::Vector2f currentCellPos = t_grid.at(m).at(i).getCellShape().getPosition();
				currentCellPos = sf::Vector2f(currentCellPos.x + offset, currentCellPos.y + offset);
				wallSprites[wallTemp].setPosition(currentCellPos);
				wallTemp++;
				t_grid.at(m).at(i).getCellShape().setFillColor(sf::Color::Blue);
			}
		}
	}
}

void Wall::checkForMousePosAndClick(sf::Vector2i t_mousePos, int t_gridParams, std::vector<std::vector<Cell>>& t_grid)
{
	for (int i = 0; i < wallTemp; i++)
	{
		if (wallSprites[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(t_mousePos)))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				resetWall(i, t_gridParams, t_grid);
			}
		}
	}

}

void Wall::resetWall(int t_currentWall, int t_gridParams, std::vector<std::vector<Cell>>& t_grid)
{
	for (int i = 0; i < t_gridParams; i++)
	{
		for (int m = 0; m < t_gridParams; m++)
		{
			if (t_grid.at(m).at(i).getCellShape().getGlobalBounds().contains(wallSprites[t_currentWall].getPosition()))
			{
				t_grid.at(m).at(i).getCellShape().setFillColor(sf::Color::Transparent);
			}
		}
	}

	wallSprites[t_currentWall].setPosition(-200, -200);
}
