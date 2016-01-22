#include "mission_view.h"
#include "debug.h"

void MissionView::Initialize()
{
	m_npcvector.push_back(std::make_unique<Npc>(m_locationvector));
	m_locationvector.push_back(std::make_shared<Location>());

	if (m_bgtexture.loadFromFile("Resources/img/background-mission.jpg"))
	{
		m_bgsprite.setTexture(m_bgtexture);
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load m_bgtexture", "state_running.cpp", "Initialize");
	}
}


void MissionView::Clean()
{

}


void MissionView::Pause()
{

}


void MissionView::Update(sf::Vector2f windowsize)
{
	// Scale background to window size
	m_bgsprite.setScale(windowsize.x / m_bgsprite.getLocalBounds().width, windowsize.y / m_bgsprite.getLocalBounds().height);

	for (auto& npc : m_npcvector)
	{
		npc->Update(windowsize);
	}

}


void MissionView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_bgsprite);

	for (auto& npc : m_npcvector)
	{
		target.draw(*npc.get());
	}

}


void MissionView::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	for (auto& npc : m_npcvector)
	{
		npc->HandleEvents(event, mousepos);
	}

}