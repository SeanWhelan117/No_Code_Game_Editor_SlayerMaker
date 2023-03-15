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
private:

	bool dataRead = false;
	std::vector<std::string> gameData;
};

