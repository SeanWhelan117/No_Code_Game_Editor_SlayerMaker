#include "LoadFromFile.h"

LoadFromFile::LoadFromFile()
{
}

void LoadFromFile::loadFile(std::string t_gameName)
{
	resetParamsForGame();
	std::fstream myFile;
	myFile.open(".\\ASSETS\\GAMEDATA\\" + t_gameName + ".csv");

	while (!myFile.eof())
	{
		std::string temp;
		//std::cout << temp << std::endl;
		getline(myFile, temp);
		gameData.push_back(temp);
	}
	

	myFile.close();

	createData();
}

void LoadFromFile::update(sf::Time t_deltaTime)
{

}

void LoadFromFile::createData()
{
	//letters used: W,S,C,D,M,H,E,G,Z

	//Each String = x, y , textureNum, ObjectType

	for (int i = 0; i < gameData.size(); i++)
	{

		std::stringstream ss(gameData.at(i));
		std::vector<std::string> substrings;
		std::string substring;

		std::string currentData = gameData.at(i);

		// Use getline with ',' delimiter to extract substrings from stringstream
		while (std::getline(ss, substring, ','))
		{
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
				if (currentData.find("W") != std::string::npos)
				{
					wallData.push_back(tempVector);
				}
				else if (currentData.find("S") != std::string::npos)
				{
					spawnerData.push_back(tempVector);
				}
				else if (currentData.find("C") != std::string::npos)
				{
					coinData.push_back(tempVector);
				}
				else if (currentData.find("D") != std::string::npos)
				{
					doorData.push_back(tempVector);
				}
				else if (currentData.find("M") != std::string::npos)
				{
					monumentData.push_back(tempVector);
				}
				else if (currentData.find("H") != std::string::npos)
				{
					medkitData.push_back(tempVector);
				}
				else if (currentData.find("E") != std::string::npos)
				{
					explosiveData.push_back(tempVector);
				}
				else if (currentData.find("N") != std::string::npos)
				{
					nukeData.push_back(tempVector);
				}
				else if (currentData.find("I") != std::string::npos)
				{
					invinceData.push_back(tempVector);
				}
				else if (currentData.find("V") != std::string::npos)
				{
					invisData.push_back(tempVector);
				}
				else if (currentData.find("Z") != std::string::npos)
				{
					BGGTChoices = tempVector;
				}
			}
		}
	}

	//std::cout << "Wall Data  Size = " << wallData.size() << std::endl;

	//for (int i = 0; i < wallData.size(); i++)
	//{
	//	std::cout << wallData.at(i).x << " --- " << wallData.at(i).y << " --- " << wallData.at(i).z << std::endl;
	//}
	//

	//std::cout << "Spawner Data  Size = " << spawnerData.size() << std::endl;

	//for (int i = 0; i < spawnerData.size(); i++)
	//{
	//	std::cout << spawnerData.at(i).x << " --- " << spawnerData.at(i).y << " --- " << spawnerData.at(i).z << std::endl;
	//}
}

void LoadFromFile::resetParamsForGame()
{
	gameData.clear();
	xPos = "";
	yPos = "";
	textureNum = "";
	wallData.clear();
	spawnerData.clear();
	coinData.clear();
	doorData.clear();
	monumentData.clear();
	explosiveData.clear();
	medkitData.clear();
	nukeData.clear();
	invinceData.clear();
	invisData.clear();
	BGGTChoices.x = 0;
	BGGTChoices.y = 0;
	BGGTChoices.z = 0;
}
