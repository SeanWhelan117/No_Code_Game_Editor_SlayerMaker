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

	if (t_wallsPlaced == true)
	{
		placeWallsOnGrid(t_grid, t_gridParams);
	}
}


void Wall::render(sf::RenderWindow& t_window)
{
	t_window.draw(wallSprite);
}

void Wall::placeWallsOnGrid(std::vector<std::vector<Cell>>& t_grid, int t_gridParams)
{
	int wallNum = 0;
	for (int i = 0; i < t_gridParams; i++)
	{
		for (int m = 0; m < t_gridParams; m++)
		{
			if (t_grid.at(m).at(i).getCellShape().getFillColor() == sf::Color::Red)
			{
				wallNum++;
				wallSprite.setPosition(t_grid.at(m).at(i).getCellShape().getPosition());
			}
		}
	}
}
