#include "Asset.h"

#include <exception>

Asset::Asset() 
{
}

void Asset::loadTexture(const std::string& key, const std::string& filepath)
{
    if (!textures[key].loadFromFile(filepath)) {
        throw std::runtime_error("Could not load texture file: " + filepath);
    }
}

sf::Texture& Asset::getTexture(const std::string &key)
{
    if (0 >= textures.count(key)) {
        throw std::runtime_error("Unknown texture key");
    }
    return textures.at(key);
}

void Asset::loadFont(const std::string& key, const std::string& filepath)
{
    if (!fonts[key].loadFromFile(filepath)) {
        throw std::runtime_error("Could not load font file: " + filepath);
    }
}

sf::Font& Asset::getFont(const std::string& key)
{
    if (0 >= fonts.count(key)) {
        throw std::runtime_error("Unknown font key");
    }
    return fonts.at(key);
}

Asset::~Asset() 
{
}
