#include "TextureManager.h"

sf::Texture& TextureManager::getTexture(const std::string& t_filename)
{
    {
        auto it = textureMap.find(t_filename);

        if (it != textureMap.end())
        {
            return it->second;
        }
        else
        {
            sf::Texture texture;
            if (!texture.loadFromFile(t_filename))
            {
                // handle error here
            }
            textureMap[t_filename] = texture;

            // Return the newly loaded texture
            return textureMap[t_filename];
        }
    }
}
