#include "TextureManager.h"

sf::Texture& TextureManager::getTexture(const std::string& t_fileName)
{
    {
        auto it = textureMap.find(t_fileName);

        if (it != textureMap.end())
        {
            return it->second;
        }
        else
        {
            sf::Texture texture;
            if (!texture.loadFromFile(t_fileName))
            {
                std::cout << "Error loading texture " << t_fileName << std::endl;
            }
            textureMap[t_fileName] = texture;

            return textureMap[t_fileName];
        }
    }
}
