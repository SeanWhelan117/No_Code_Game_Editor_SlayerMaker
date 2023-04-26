#include "SoundManager.h"

void SoundManager::loadSound(const std::string& t_soundName, const std::string& t_soundFile)
{
    sf::SoundBuffer buffer;

    if (buffer.loadFromFile(t_soundFile)) 
    {
        m_soundBuffers[t_soundName] = buffer;
    }
}

void SoundManager::playSound(const std::string& t_soundName) 
{
    auto soundBuffer = m_soundBuffers.find(t_soundName);

    if (soundBuffer != m_soundBuffers.end()) 
    {
        sf::Sound sound(soundBuffer->second);
        sound.play();
    }
}
