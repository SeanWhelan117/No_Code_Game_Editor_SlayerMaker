/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
class Builder
{
public:
	Builder();
	void buildGame(std::string t_gameName);
private:
};

