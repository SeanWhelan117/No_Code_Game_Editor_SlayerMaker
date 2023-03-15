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
		std::cout << temp << std::endl;
		getline(myFile, temp);
		gameData.push_back(temp);
	}
	dataRead = true;
	myFile.close();
}

void LoadFromFile::update(sf::Time t_deltaTime)
{
	if (dataRead == true)
	{
		gameData;
	}
}
