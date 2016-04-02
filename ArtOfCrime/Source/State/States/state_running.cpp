#include "state_running.h"
#include "SFML\Graphics\RenderTarget.hpp"
#include "SFML\Graphics\RenderStates.hpp"

#include "debug.h"
#include "view_team.h"

#include "object.h"

StateRunning::StateRunning()
{
    m_object_manager.AddAlly("John", "A cool guy", TextureData("Resources/Img/Hud/npc_john.png", sf::Vector2f(0.5f, 0.5f)));
    m_object_manager.AddAlly("Eric", "A cool spy", TextureData("Resources/Img/Hud/npc_john.png", sf::Vector2f(0.5f, 0.5f)));

    m_object_manager.AddLocation("The plaza");
    m_object_manager.AddLocation("The bank");

    for (unsigned int i = 0; i < m_object_manager.GetAllyCount(); i++)
    {
        m_gui.CreateButton<void, ViewManager, NPC&, std::vector<Location>&>("Resources/Img/Hud/npc.png", "Resources/Img/Hud/npc_hoover.png",
            sf::Vector2f(0.3f, 0.3f), sf::Vector2f(65.f*i, 535.f), &ViewManager::ChangeView<ViewTeam, NPC&, std::vector<Location>&>, m_view_manager, m_object_manager.GetAllyAt(i), m_object_manager.GetLocations());
    }
	
}

void StateRunning::Initialize()
{
}

void StateRunning::Clean()
{
	
}

void StateRunning::Pause()
{

}


void StateRunning::Update(sf::Vector2f windowsize)
{
	m_view_manager.Update(windowsize);
	m_gui.Update(windowsize);
}

void StateRunning::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_view_manager.Draw(target, states);
	m_gui.Draw(target, states);
}

void StateRunning::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	m_view_manager.HandleEvents(event, mousepos);
	m_gui.HandleEvents(event, mousepos);
}

