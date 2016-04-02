#pragma once
#include "runnable_drawable.h"
#include "npc.h"
#include "location.h"
#include <vector>
#include <memory>
#include <string>

class ObjectManager
{
public:
    ObjectManager()
    {

    }

    ~ObjectManager(){}

    void Update(sf::Vector2f windowsize)
    {

    }

    void HandleEvents(sf::Event event, sf::Vector2i mousepos)
    {

    }

    void Draw(sf::RenderTarget& target, sf::RenderStates states) const
    {

    }

    void AddAlly(std::string name, std::string description, TextureData texture_data)
    {
        m_allies.push_back(std::make_unique<NPC>(name, description, texture_data));
    }

    NPC& GetAllyAt(unsigned int index)
    {
        if (index < m_allies.size())
        {
            return *m_allies.at(index);
        }
        else
        {
            throw std::out_of_range("This ally does not exist");
        }
    }

    unsigned int GetAllyCount()
    {
        return m_allies.size();
    }

    void AddLocation(std::string name)
    {
        m_locations.push_back(Location(name));
    }

    std::vector<Location>& GetLocations()
    {
        return m_locations;
    }

private:
    std::vector<std::unique_ptr<NPC> > m_allies;
    std::vector<Location> m_locations;
};

