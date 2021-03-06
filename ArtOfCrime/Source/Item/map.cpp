#include "map.h"
#include <iostream>

Map::Map() :
    Item("Map", "A map", 20, 20)
{
    if (m_texture.loadFromFile("Resources/map.gif"))
    {
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
    }
    else
    {
        std::cout << "Warning: Failed to load m_texture_detailed @ map.cpp : Map()" << std::endl;
    }

    m_detailed = std::make_unique<InspectItem>("Map", "A map", "Resources/map.gif", 0.7f, 0.7f);
}


Map::~Map()
{

}

