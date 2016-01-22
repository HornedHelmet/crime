#include "state_running.h"
#include "npc.h"
#include "mission_view.h"
#include "board_view.h"
#include "debug.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Knappar måste rendreras här ute för att kunna swapa mellen views
void StateRunning::Initialize()
{
	m_sm_view = std::make_unique<StateManager>(&BoardView::GetInstance());
}

void StateRunning::Clean()
{

}

void StateRunning::Pause()
{

}

void StateRunning::Update(sf::Vector2f windowsize)
{
	if (m_button_missionview.IsClicked())
	{
		m_sm_view->ChangeState(&MissionView::GetInstance());
		m_button_missionview.SetIsClicked(false);
	}

	m_sm_view->Update(windowsize);

}


void StateRunning::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_sm_view.get());
	target.draw(m_button_missionview);
}

void StateRunning::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	m_button_missionview.HandleEvents(event, mousepos);
	m_sm_view->HandleEvents(event, mousepos);

}

