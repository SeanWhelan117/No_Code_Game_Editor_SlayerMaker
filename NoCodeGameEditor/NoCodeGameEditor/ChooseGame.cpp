#include "ChooseGame.h"

ChooseGame::ChooseGame(float t_gameWidth, float t_gameHeight, NetworkManager& t_networkManager) : gameWidth(t_gameWidth), gameHeight(t_gameHeight), m_networkManager(t_networkManager)
{
	loadFontAndSprites();
	findFiles();
	setupButtons();
}

void ChooseGame::loadFontAndSprites()
{
	if (!font.loadFromFile("./ASSETS/FONTS/NewYork.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}

	if (!buildTexture.loadFromFile("ASSETS\\IMAGES\\buttonBuild.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading buildTexture (buttonBuild)" << std::endl;
	}

	if (!uploadTexture.loadFromFile("ASSETS\\IMAGES\\buttonUpDown.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading uploadTexture (buttonUpDown)" << std::endl;
	}

	if (!deleteTexture.loadFromFile("ASSETS\\IMAGES\\buttonDelete.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading deleteTexture (buttonDelete)" << std::endl;
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
		initialPos = sf::Vector2f(200, 300);
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
		if (count > 7)
		{
			count = 0;
			initialPos.x = 200;
			initialPos.y += 350;
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
	titleText.setFont(font);
	titleText.setFillColor(sf::Color::Black);
	titleText.setCharacterSize(85u);
	titleText.setString("Choose a Game to Play");
	//titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);

	titleText.setPosition(50,50);
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

}

void ChooseGame::render(sf::RenderWindow& t_window)
{
	t_window.clear(sf::Color(81, 81, 81, 150));
	t_window.draw(titleText);
	if (levelRectsCreated)
	{
		for (int i = 0; i < games.size(); i++)
		{
			t_window.draw(bgRects.at(i));
			t_window.draw(games.at(i));
			t_window.draw(nameTexts.at(i));
			t_window.draw(buildButtons.at(i));
			t_window.draw(uploadButtons.at(i));
			t_window.draw(deleteButtons.at(i));
			t_window.draw(buildSprites.at(i));
			t_window.draw(uploadSprites.at(i));
			t_window.draw(deleteSprites.at(i));

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
			if (buttonClicked)
			{
				std::cout << gameNames.at(i) << std::endl;
				loader.loadFile(gameNames.at(i));
				gameChosen = true;
				buttonClicked = false;
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

			if (buttonClicked && gameBuilt == false)
			{
				/*gameBuilt = true;
				chosenGame = gameNames.at(i);
				loader.loadFile(gameNames.at(i));
				gameChosen = true;*/
				buttonClicked = false;
			}
		}
		else
		{
			resetButtons(buildButtons.at(i));
		}

		if (containsMouse(uploadButtons.at(i).getGlobalBounds()))
		{
			changeButtons(uploadButtons.at(i));

			if (buttonClicked)
			{
				buttonClicked = false;
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

			if (buttonClicked)
			{
				deleteFile(gameNames.at(i));
				buttonClicked = false;
			}
		}
		else
		{
			resetButtons(deleteButtons.at(i));
		}
	}
	buttonClicked = false;
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


		sf::RectangleShape tempRect4;
		tempRect4.setFillColor(sf::Color(120, 120, 120, 175));
		tempRect4.setSize(sf::Vector2f(350, 250));
		tempRect4.setOrigin(tempRect4.getLocalBounds().width / 2, tempRect4.getLocalBounds().height / 2);
		tempRect4.setPosition(games.at(i).getPosition().x , games.at(i).getPosition().y + games.at(i).getGlobalBounds().height / 2);
		bgRects.push_back(tempRect4);
	}

	for (int i = 0; i < games.size(); i++)
	{
		sf::Sprite tempSprite;
		tempSprite.setTexture(buildTexture);
		tempSprite.setOrigin(tempSprite.getGlobalBounds().width / 2, tempSprite.getGlobalBounds().height / 2);
		tempSprite.setPosition(buildButtons.at(i).getPosition());
		buildSprites.push_back(tempSprite);

		sf::Sprite tempSprite2;
		tempSprite2.setTexture(uploadTexture);
		tempSprite2.setOrigin(tempSprite2.getGlobalBounds().width / 2, tempSprite2.getGlobalBounds().height / 2);
		tempSprite2.setPosition(uploadButtons.at(i).getPosition());
		uploadSprites.push_back(tempSprite2);

		sf::Sprite tempSprite3;
		tempSprite3.setTexture(deleteTexture);
		tempSprite3.setOrigin(tempSprite3.getGlobalBounds().width / 2, tempSprite3.getGlobalBounds().height / 2);
		tempSprite3.setPosition(deleteButtons.at(i).getPosition());
		deleteSprites.push_back(tempSprite3);
	}

}

void ChooseGame::deleteFile(std::string t_filename)
{

	std::filesystem::path directoryPath(".\\ASSETS\\GAMEDATA\\");
	std::filesystem::path filePath = directoryPath / (t_filename + ".csv");

	//std::filesystem::path filePath(".\\NoCodeGameEditor\\ASSETS\\GAMEDATA\\" + t_filename + ".csv");

	// Check if the file exists
	if (std::filesystem::exists(filePath))
	{
		// Delete the file
		std::filesystem::remove(filePath);
		std::cout << "File " << t_filename << " deleted successfully." << std::endl;
		findFiles();
		
	}
	else
	{
		std::cout << "File " << t_filename << " does not exist." << std::endl;
	}
}

