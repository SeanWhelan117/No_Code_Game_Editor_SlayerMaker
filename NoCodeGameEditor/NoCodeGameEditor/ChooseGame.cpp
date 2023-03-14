#include "ChooseGame.h"

ChooseGame::ChooseGame(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
	findFiles();
	setupSprites();
}

void ChooseGame::findFiles()
{
	std::filesystem::path p1{ ".\\ASSETS\\GAMEDATA" };

	for (auto& p : std::filesystem::directory_iterator(p1))
	{
		++fileCount;
	}

	std::cout << "# of files in " << p1 << ": " << fileCount << '\n';
}

void ChooseGame::setupSprites()
{
	int count = 0;
	for (int i = 0; i < fileCount; i++)
	{
		sf::RectangleShape testRect;
		testRect.setFillColor(sf::Color::Blue);
		testRect.setSize(sf::Vector2f( 100, 100));
		testRect.setPosition(initialPos);
		count++;
		if (count > 4)
		{
			count = 0;
			initialPos.x = 100;
			initialPos.y += 150;
		}
		else
		{
			initialPos.x += 150;
		}
		games.push_back(testRect);
	}

	levelRectsCreated = true;
}

void ChooseGame::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{

}

void ChooseGame::render(sf::RenderWindow& t_window)
{
	if (levelRectsCreated)
	{
		for (int i = 0; i < games.size(); i++)
		{
			t_window.draw(games.at(i));
		}
	}
	
}
