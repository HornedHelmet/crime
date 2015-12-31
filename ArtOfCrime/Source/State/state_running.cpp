#include "state_running.h"
#include "map.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void StateRunning::Initialize()
{
    m_itemvector.push_back(std::make_unique<Map>());
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
    for (auto& item : m_itemvector)
    {
        target.draw(*item.get());
    }
}

void StateRunning::HandleEvents(sf::Event event)
{

    for (auto& item : m_itemvector)
    {
        item->HandleEvents(event);
    }

}
