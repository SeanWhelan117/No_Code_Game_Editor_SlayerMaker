#include "ChooseGame.h"

ChooseGame::ChooseGame(float t_gameWidth, float t_gameHeight)
{
	gameWidth = t_gameWidth;
	gameHeight = t_gameHeight;
	loadFont();
	findFiles();
	setupBuildButtons();
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
		testRect.setOrigin(testRect.getLocalBounds().width / 2, testRect.getLocalBounds().height / 2);
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
	if (levelRectsCreated)
	{
		for (int i = 0; i < games.size(); i++)
		{
			t_window.draw(games.at(i));
			t_window.draw(nameTexts.at(i));
			t_window.draw(buildButtons.at(i));
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

		if (buildButtons.at(i).getGlobalBounds().contains(mousePos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && gameBuilt == false)
			{
				gameBuilt = true;
				buildGame(i);
			}
		}
	}
	if (mousePos.x > 300)
	{
		gameBuilt = false;
	}
}

void ChooseGame::setupBuildButtons()
{
	for (int i = 0; i < games.size(); i++)
	{
		sf::RectangleShape tempRect;
		tempRect.setFillColor(sf::Color::Green);
		tempRect.setPosition(games.at(i).getPosition().x, games.at(i).getPosition().y + 90);
		tempRect.setSize(sf::Vector2f(100, 75));
		tempRect.setOrigin(tempRect.getLocalBounds().width / 2, tempRect.getLocalBounds().height / 2);
		buildButtons.push_back(tempRect);
	}
}

void ChooseGame::buildGame(int t_game)
{
	
	// Create build directory
	std::string build_dir = "build";
	std::filesystem::create_directory(build_dir);

	// Copy game files
	//std::string game_dir = "NoCodeGameEditor";

	std::filesystem::path current_dir = std::filesystem::current_path();
	//std::filesystem::path game_path = current_dir / game_dir;
	
	if (!std::filesystem::exists(current_dir))
	{
		// handle the case where the directory doesn't exist
		std::cout << "doesnt exist" << std::endl;
	}
	else 
	{
		for (auto& file : std::filesystem::directory_iterator(current_dir))
		{
			if (file.is_regular_file() && (file.path().extension() == ".cpp" || file.path().extension() == ".h"))
			{
				std::filesystem::copy(file.path(), build_dir + "\\" + file.path().filename().string());
			}
		}
	}

	// Compile the game
	std::string compiler_path = R"(C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64\cl.exe)";
	std::string command = "\"" + compiler_path + "\" /EHsc \"" + build_dir + "\\main.cpp\" /Fe:\"" + build_dir + "\\game.exe\"";
	std::system(command.c_str());

	// Copy DLLs
	std::string sfml_dir = "C:\\SFML-2.5.1\\bin";
	for (auto& file : std::filesystem::directory_iterator(sfml_dir))
	{
		if (file.is_regular_file() && file.path().extension() == ".dll")
		{
			std::filesystem::copy(file.path(), build_dir + "\\" + file.path().filename().string());
		}
	}

	// Copy assets
	std::string asset_dir = "ASSETS";
	for (auto& file : std::filesystem::recursive_directory_iterator(asset_dir))
	{
		if (file.is_regular_file())
		{
			auto relative_path = std::filesystem::relative(file.path(), asset_dir);
			auto dest_path = build_dir / relative_path;
			std::filesystem::create_directories(dest_path.parent_path());
			std::filesystem::copy(file.path(), dest_path);
		}
	}

	// Zip the build directory
	std::string zip_file = "game.zip";
	command = "powershell Compress-Archive -Path \"" + build_dir + "\\*\" -DestinationPath \"" + zip_file + "\"";
	std::system(command.c_str());

	std::cout << "Game executable built: " << zip_file << std::endl;

}
