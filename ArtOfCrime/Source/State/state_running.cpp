#include "state_running.h"
#include "npc.h"

#include <SFML/Graphics.hpp>
#include <iostream>

void StateRunning::Initialize()
{
    m_itemvector.push_back(std::make_unique<Item>("map", "a map", "Resources/map.gif", 0.3f, 200.f, 200.f, "Resources/map.gif", 0.4f));
	m_npcvector.push_back(std::make_unique<Npc>(m_locationvector));
	m_locationvector.push_back(std::make_shared<Location>());
}

void StateRunning::Clean()
{

}

void StateRunning::Pause()
{

}

void StateRunning::Update(float time)
{
	for (auto& npc : m_npcvector)
	{
		npc->Update(time);
	}

	for (auto& item : m_itemvector)
	{
		item->Update(time);
	}
}

void StateRunning::Draw(sf::RenderTarget& target)
{
    for (auto& npc : m_npcvector)
    {
        target.draw(*npc.get());
    }

    for (auto& item : m_itemvector)
    {
        target.draw(*item.get());
    }
}

void StateRunning::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
    for (auto& npc : m_npcvector)
    {
		npc->HandleEvents(event, mousepos);
    }

    for (auto& item : m_itemvector)
    {
        item->HandleEvents(event, mousepos);
    }

}

