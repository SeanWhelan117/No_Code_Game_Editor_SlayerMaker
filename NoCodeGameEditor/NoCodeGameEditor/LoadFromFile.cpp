#include "LoadFromFile.h"

LoadFromFile::LoadFromFile()
{
}

void LoadFromFile::loadFile(std::string t_gameName)
{
	std::fstream myFile;
	myFile.open(".\\ASSETS\\GAMEDATA\\" + t_gameName + ".csv");

	while (!myFile.eof())
	{
		std::string temp;
		//std::cout << temp << std::endl;
		getline(myFile, temp);
		gameData.push_back(temp);
	}
	
	std::vector<std::string>::iterator it;

	it = gameData.begin();
	gameData.erase(it);
	it = gameData.begin();
	gameData.erase(it);
	it = gameData.begin();

	for (int i = 0; i < gameData.size(); i++)
	{
		//it++;
		//if (gameData.at(i) == "")
		//{

		//}
		std::cout << gameData.at(i) << std::endl;
	}
	//dataRead = true;
	myFile.close();
}

void LoadFromFile::update(sf::Time t_deltaTime)
{
	/*if (dataRead == true)
	{
		gameData;
	}*/
}
