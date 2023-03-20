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
	
	parseVectorsFromFile();
	
	

	for (int i = 0; i < gameData.size(); i++)
	{

		std::cout << gameData.at(i) << std::endl;
	}

	myFile.close();

	createData();
}

void LoadFromFile::update(sf::Time t_deltaTime)
{

}

void LoadFromFile::parseVectorsFromFile()
{
	std::vector<std::string>::iterator it;

	it = gameData.begin();
	gameData.erase(it);
	it = gameData.begin();
	gameData.erase(it);
	it = gameData.begin();

	it = std::find(gameData.begin(), gameData.end(), "SPAWNERS,");
	if (it != gameData.end())
	{
		gameData.erase(it);
	}

	it = gameData.begin();

	it = std::find(gameData.begin(), gameData.end(), "X,Y,Type,Object,");
	if (it != gameData.end())
	{
		gameData.erase(it);
	}
}

void LoadFromFile::createData()
{
	//Each String = x, y , textureNum, ObjectType

	for (int i = 0; i < gameData.size(); i++)
	{
		if (gameData.at(i).find("W"))
		{
			//std::cout << "WALL" << std::endl;
			std::stringstream ss(gameData.at(i));

			std::vector<std::string> substrings;
			std::string substring;

			// Use getline with ',' delimiter to extract substrings from stringstream
			while (std::getline(ss, substring, ',')) {
				substrings.push_back(substring);
			}
			if (substrings.size() > 0)
			{
				if (!substrings.at(0).empty())
				{
					xPos = substrings.at(0);
				}
				if (!substrings.at(1).empty())
				{
					yPos = substrings.at(1);

				}
				if (!substrings.at(2).empty())
				{
					textureNum = substrings.at(2);
				}
				if (!xPos.empty() && !yPos.empty() && !textureNum.empty())
				{
					sf::Vector3f tempVector = { std::stof(xPos), std::stof(yPos), std::stof(textureNum) };
					wallData.push_back(tempVector);
				}
			}
		}
		else if (gameData.at(i).find("S"))
		{
			std::stringstream ss(gameData.at(i));

			std::vector<std::string> substrings;
			std::string substring;

			// Use getline with ',' delimiter to extract substrings from stringstream
			while (std::getline(ss, substring, ',')) {
				substrings.push_back(substring);
			}
			if (substrings.size() > 0)
			{
				if (!substrings.at(0).empty())
				{
					xPos = substrings.at(0);
				}
				if (!substrings.at(1).empty())
				{
					yPos = substrings.at(1);

				}
				if (!substrings.at(2).empty())
				{
					textureNum = substrings.at(2);
				}
				if (!xPos.empty() && !yPos.empty() && !textureNum.empty())
				{
					sf::Vector3f tempVector = { std::stof(xPos), std::stof(yPos), std::stof(textureNum) };
					wallData.push_back(tempVector);
				}
			}
		}
			
	}



	/*for (int i = 0; i < wallData.size(); i++)
	{
		std::cout << std::to_string(wallData.at(i).x) << "  " << std::to_string(wallData.at(i).y) << "  " << std::to_string(wallData.at(i).z) << std::endl;
	}*/

	//std::string input_string = "Hello,World,How,Are,You";

	//// Create a stringstream from the input string
	//std::stringstream ss(input_string);

	//std::vector<std::string> substrings;
	//std::string substring;

	//// Use getline with ',' delimiter to extract substrings from stringstream
	//while (std::getline(ss, substring, ',')) {
	//	substrings.push_back(substring);
	//}

	//// Print the substrings
	//for (const auto& s : substrings) {
	//	std::cout << s << std::endl;
	//}
}
