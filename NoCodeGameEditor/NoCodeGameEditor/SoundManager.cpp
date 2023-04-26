#include "SoundManager.h"

void SoundManager::loadSound(const std::string& t_soundName, const std::string& t_soundFile)
{
    sf::SoundBuffer buffer;

    if (buffer.loadFromFile(t_soundFile)) 
    {
        m_soundBuffers[t_soundName] = buffer;
    }


}
