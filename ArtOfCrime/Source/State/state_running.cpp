#include "state_running.h"
#include "map.h"
#include "npc.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void StateRunning::Initialize()
{
    m_itemvector.push_back(std::make_unique<Map>());
    m_actorvector.push_back(std::make_unique<Npc>());
}

void StateRunning::Clean()
{

}

void StateRunning::Pause()
{

}

void StateRunning::Update(float time)
{

}

void StateRunning::Draw(sf::RenderTarget& target)
{
    for (auto& actor : m_actorvector)
    {
        target.draw(*actor.get());
    }

    for (auto& item : m_itemvector)
    {
        target.draw(*item.get());
    }
}

void StateRunning::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
    for (auto& actor : m_actorvector)
    {
        actor->HandleEvents(event, mousepos);
    }

    for (auto& item : m_itemvector)
    {
        item->HandleEvents(event, mousepos);
    }

}
