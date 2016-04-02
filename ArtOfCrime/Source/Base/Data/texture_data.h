#pragma once
#include <SFML\System\Vector2.hpp>
#include <string>

struct TextureData
{
public:
    std::string path;
    sf::Vector2f scale;

    TextureData(std::string inpath, sf::Vector2f inscale) :
        path(inpath),
        scale(inscale)
    {}
};