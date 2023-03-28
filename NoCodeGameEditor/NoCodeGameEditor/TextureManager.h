/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class TextureManager
{
public:
    TextureManager() {}

    sf::Texture& getTexture(const std::string& t_filename);
    

private:
    std::map<std::string, sf::Texture> textureMap;
};

