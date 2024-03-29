/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


class LoadFromFile
{
public:
	LoadFromFile();

	void loadFile(std::string t_gameName);

	void update(sf::Time t_deltaTime);
	void createData();
	void resetParamsForGame();
	std::vector<sf::Vector3f> wallData;
	std::vector<sf::Vector3f> spawnerData;
	std::vector<sf::Vector3f> coinData;
	std::vector<sf::Vector3f> doorData;
	std::vector<sf::Vector3f> monumentData;
	std::vector<sf::Vector3f> medkitData;
	std::vector<sf::Vector3f> explosiveData;
	std::vector<sf::Vector3f> nukeData;
	std::vector<sf::Vector3f> invinceData;
	std::vector<sf::Vector3f> invisData;

	sf::Vector3f BGGTChoices;


private:

	bool dataRead = false;
	std::vector<std::string> gameData;
	std::string xPos;
	std::string yPos;
	std::string textureNum;
};

