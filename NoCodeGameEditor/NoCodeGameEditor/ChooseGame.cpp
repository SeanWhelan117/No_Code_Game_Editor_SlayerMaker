#include "ChooseGame.h"

ChooseGame::ChooseGame(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
	loadFont();
	findFiles();
	//setupSprites();
	//setupNames();
}

void ChooseGame::loadFont()
{
	if (!font.loadFromFile("./ASSETS/FONTS/NewYork.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}
}

void ChooseGame::findFiles()
{
	if (gameNames.size() != 0)
	{
		gameNames.clear();
		fileCount = 0;
		games.clear();
		nameTexts.clear();
		initialPos = sf::Vector2f(100, 100);
	}

	std::filesystem::path p1{ ".\\ASSETS\\GAMEDATA" };

	for (auto& p : std::filesystem::directory_iterator(p1))
	{
		//std::cout << p.path() << std::endl;
		std::string tempString = p.path().string();
		tempString.erase(0, 18);
		for (int i = 0; i < 4; i++)
		{
			tempString.pop_back();
		}
		
		gameNames.push_back(tempString);
		++fileCount;
	}

	std::cout << "# of files in " << p1 << ": " << fileCount << '\n';

	setupSprites();
}

void ChooseGame::setupSprites()
{
	int count = 0;
	for (int i = 0; i < fileCount; i++)
	{
		sf::RectangleShape testRect;
		testRect.setFillColor(sf::Color::Yellow);
		testRect.setSize(sf::Vector2f( 300, 100));
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
			initialPos.x += 400;
		}
		games.push_back(testRect);
	}

	for (int i = 0; i < gameNames.size(); i++)
	{
		std::cout << gameNames.at(i) << std::endl;
	}
	
	levelRectsCreated = true;
	setupNames();
}

void ChooseGame::setupNames()
{

	for (int i = 0; i < fileCount; i++)
	{
		sf::Text tempText;
		tempText.setFont(font);
		tempText.setFillColor(sf::Color::Black);
		tempText.setCharacterSize(30u);
		tempText.setString(gameNames.at(i));
		tempText.setPosition(games.at(i).getPosition());
		nameTexts.push_back(tempText);
	}
}

void ChooseGame::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));

	checkForMousePos();

	loader.update(t_deltaTime);
}

void ChooseGame::render(sf::RenderWindow& t_window)
{
	if (levelRectsCreated)
	{
		for (int i = 0; i < games.size(); i++)
		{
			t_window.draw(games.at(i));
			t_window.draw(nameTexts.at(i));
		}
	}
	
}

void ChooseGame::checkForMousePos()
{
	for (int i = 0; i < games.size(); i++)
	{
		if (games.at(i).getGlobalBounds().contains(mousePos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << gameNames.at(i) << std::endl;
				loader.loadFile(gameNames.at(i));
				gameChosen = true;
			}
			else
			{
				gameChosen = false;
			}
		}
	}
}
