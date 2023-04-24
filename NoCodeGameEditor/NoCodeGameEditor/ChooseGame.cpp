#include "ChooseGame.h"

ChooseGame::ChooseGame(float t_gameWidth, float t_gameHeight, NetworkManager& t_networkManager) : gameWidth(t_gameWidth), gameHeight(t_gameHeight), m_networkManager(t_networkManager)
{
	loadFont();
	findFiles();
	setupButtons();
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
		initialPos = sf::Vector2f(200, 100);
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
		testRect.setOrigin(testRect.getLocalBounds().width / 2, testRect.getLocalBounds().height / 2);
		testRect.setPosition(initialPos);
		count++;
		if (count > 4)
		{
			count = 0;
			initialPos.x = 200;
			initialPos.y += 250;
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
		tempText.setOrigin(tempText.getLocalBounds().width / 2, tempText.getLocalBounds().height / 2);
		tempText.setPosition(games.at(i).getPosition());
		nameTexts.push_back(tempText);
	}
}

void ChooseGame::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	mousePos = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));

	checkForMousePos();

	loader.update(t_deltaTime);

	if (savedToDB == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		savedToDB = false;
	}
}

void ChooseGame::render(sf::RenderWindow& t_window)
{
	if (levelRectsCreated)
	{
		for (int i = 0; i < games.size(); i++)
		{
			t_window.draw(games.at(i));
			t_window.draw(nameTexts.at(i));
			t_window.draw(buildButtons.at(i));
			t_window.draw(uploadButtons.at(i));
			t_window.draw(deleteButtons.at(i));
		}
	}
	
}
bool ChooseGame::containsMouse(sf::FloatRect t_rectShape)
{
	return t_rectShape.contains(mousePos);
}

void ChooseGame::checkForMousePos()
{
	for (int i = 0; i < games.size(); i++)
	{
		if (containsMouse(games.at(i).getGlobalBounds()))
		{
			changeButtons(games.at(i));
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
		else
		{
			resetButtons(games.at(i));
		}

		if (containsMouse(buildButtons.at(i).getGlobalBounds()))
		{
			changeButtons(buildButtons.at(i));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && gameBuilt == false)
			{
				/*gameBuilt = true;
				chosenGame = gameNames.at(i);
				loader.loadFile(gameNames.at(i));
				gameChosen = true;*/
			}
		}
		else
		{
			resetButtons(buildButtons.at(i));
		}

		if (containsMouse(uploadButtons.at(i).getGlobalBounds()))
		{
			changeButtons(uploadButtons.at(i));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && savedToDB == false)
			{
				savedToDB = true;
				m_networkManager.writeGameDataToDB(gameNames.at(i));
			}
		}
		else
		{
			resetButtons(uploadButtons.at(i));
		}
		
		
		if (containsMouse(deleteButtons.at(i).getGlobalBounds()))
		{
			changeButtons(deleteButtons.at(i));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

			}
		}
		else
		{
			resetButtons(deleteButtons.at(i));
		}
	}
	
}

void ChooseGame::resetButtons(sf::RectangleShape& t_rect)
{
	t_rect.setScale(1, 1);
}

void ChooseGame::changeButtons(sf::RectangleShape& t_rect)
{
	t_rect.setScale(1.2, 1.2);
}

void ChooseGame::setupButtons()
{
	float offset = games.at(0).getLocalBounds().width / 3;
	sf::Vector2f buttonSize = sf::Vector2f(games.at(0).getLocalBounds().width / 3, 75);

	for (int i = 0; i < games.size(); i++)
	{
		sf::RectangleShape tempRect;
		tempRect.setFillColor(sf::Color::Green);
		tempRect.setSize(buttonSize);
		tempRect.setOrigin(tempRect.getLocalBounds().width / 2, tempRect.getLocalBounds().height / 2);
		tempRect.setPosition(games.at(i).getPosition().x - offset, games.at(i).getPosition().y + games.at(i).getLocalBounds().height / 2 + tempRect.getLocalBounds().height / 2);
		buildButtons.push_back(tempRect);

		sf::RectangleShape tempRect2;
		tempRect2.setFillColor(sf::Color::Blue);
		tempRect2.setSize(buttonSize);
		tempRect2.setOrigin(tempRect2.getLocalBounds().width / 2, tempRect2.getLocalBounds().height / 2);
		tempRect2.setPosition(games.at(i).getPosition().x, games.at(i).getPosition().y + games.at(i).getLocalBounds().height / 2 + tempRect2.getLocalBounds().height / 2);
		uploadButtons.push_back(tempRect2);

		sf::RectangleShape tempRect3;
		tempRect3.setFillColor(sf::Color::Red);
		tempRect3.setSize(buttonSize);
		tempRect3.setOrigin(tempRect3.getLocalBounds().width / 2, tempRect3.getLocalBounds().height / 2);
		tempRect3.setPosition(games.at(i).getPosition().x + offset, games.at(i).getPosition().y + games.at(i).getLocalBounds().height / 2 + tempRect3.getLocalBounds().height / 2);
		deleteButtons.push_back(tempRect3);
	}
}

