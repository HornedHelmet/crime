#include "state_running.h"
#include "SFML\Graphics\RenderTarget.hpp"
#include "SFML\Graphics\RenderStates.hpp"

#include "debug.h"
#include "view_team.h"

#include "object.h"

StateRunning::StateRunning()
{
	m_npc1.SetName("John");
	m_npc2.SetName("Eric");
	m_view_manager.PushView<ViewMain>();
	m_hud.CreateButton<void, ViewManager, AObject&>("Resources/Img/Hud/npc.png", "Resources/Img/Hud/npc_hoover.png", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(0.f, 535.f), &ViewManager::PushView<ViewTeam>, m_view_manager, m_npc1);
	m_hud.CreateButton<void, ViewManager, AObject&>("Resources/Img/Hud/npc.png", "Resources/Img/Hud/npc_hoover.png", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(65.f, 535.f), &ViewManager::PushView<ViewTeam>, m_view_manager, m_npc2);
	/*m_hud.CreateButton<void, StateRunning, NPC&>("Resources/Img/Hud/npc.png", "Resources/Img/Hud/npc_hoover.png", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(50.f, 535.f), &StateRunning::test, *this, npc2);
	m_hud.CreateButton<void, StateRunning, NPC&>("Resources/Img/Hud/npc.png", "Resources/Img/Hud/npc_hoover.png", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(100.f, 535.f), &StateRunning::test, *this, npc3);*/
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
	m_hud.Update(windowsize);
	m_view_manager.Update(windowsize);
}

void StateRunning::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_hud.Draw(target, states);
	m_view_manager.Draw(target, states);
}

void StateRunning::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	m_hud.HandleEvents(event, mousepos);
	m_view_manager.HandleEvents(event, mousepos);
}

