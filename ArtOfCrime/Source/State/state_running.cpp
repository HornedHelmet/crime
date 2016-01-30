#include "state_running.h"
#include "npc.h"
#include "mission_view.h"
#include "board_view.h"
#include "debug.h"
#include <SFML/Graphics.hpp>
#include <iostream>


void StateRunning::Initialize()
{
	m_sm_view = std::make_shared<StateManager>(&BoardView::GetInstance());
	m_view_buttons.push_back(std::make_unique<gui::ChangeStateButton>("1", "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f), m_sm_view, &BoardView::GetInstance()));
	m_view_buttons.push_back(std::make_unique<gui::ChangeStateButton>("2", "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(150.f, 0.f), m_sm_view, &MissionView::GetInstance()));

}

void StateRunning::Clean()
{
	
}

void StateRunning::Pause()
{

}

void StateRunning::Update(sf::Vector2f windowsize)
{
	m_sm_view->Update(windowsize);
}


void StateRunning::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_sm_view.get());
	
	for (auto& button : m_view_buttons)
	{
		target.draw(*button.get());
	}
}

void StateRunning::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	
	for (auto& button : m_view_buttons)
	{
		button->HandleEvents(event, mousepos);
	}

	m_sm_view->HandleEvents(event, mousepos);

}

