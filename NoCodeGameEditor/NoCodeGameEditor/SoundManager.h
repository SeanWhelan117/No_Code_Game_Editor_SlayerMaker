/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Audio.hpp>

class SoundManager
{
public:
    static SoundManager& getInstance() 
    {
        static SoundManager instance;
        return instance;
    }

    void loadSound(const std::string& t_soundName, const std::string& t_soundFile);

    void playSound(const std::string& t_soundName);


private:
    SoundManager() {}

    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;

    std::map<std::string, sf::SoundBuffer> m_soundBuffers;
};

