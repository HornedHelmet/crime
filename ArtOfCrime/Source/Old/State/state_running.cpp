#include "state_running.h"
#include "npc.h"
#include "mission_view.h"
#include "board_view.h"
#include "debug.h"
#include <SFML/Graphics.hpp>
#include <iostream>


StateRunning::StateRunning()
{
	m_npcvector.push_back(std::make_unique<Npc>("Name1", "Description", "Resources/img/detective.gif", "Resources/img/detective_hoover.gif", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(400.f, 100.f), m_locationvector));
	m_npcvector.push_back(std::make_unique<Npc>("Name2", "Description", "Resources/img/detective.gif", "Resources/img/detective_hoover.gif", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(400.f, 100.f), m_locationvector));
	m_locationvector.push_back(std::make_shared<Location>("Name", "Description", "Resources/img/location.jpg", "Resources/img/location_hoover.jpg", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(200.f, 100.f)));

	m_hud = std::make_unique<Hud<State, void, Actor&>>(*this, &State::_GuiElementClicked_);

	m_hud->CreateButton(*this, *m_npcvector.back().get(), &State::_GuiElementClicked_);
}

void StateRunning::Initialize()
{
	/*m_sm_view = std::make_shared<StateManager>(&BoardView::GetInstance());
	m_view_buttons.push_back(std::make_unique<gui::ChangeStateButton>("1", "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f), m_sm_view, &BoardView::GetInstance()));
	m_view_buttons.push_back(std::make_unique<gui::ChangeStateButton>("2", "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(150.f, 0.f), m_sm_view, &MissionView::GetInstance()));*/
	
	m_npcvector.push_back(std::make_unique<Npc>("Name1", "Description", "Resources/img/detective.gif", "Resources/img/detective_hoover.gif", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(400.f, 100.f), m_locationvector));
	m_npcvector.push_back(std::make_unique<Npc>("Name2", "Description", "Resources/img/detective.gif", "Resources/img/detective_hoover.gif", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(400.f, 100.f), m_locationvector));
	m_locationvector.push_back(std::make_shared<Location>("Name", "Description", "Resources/img/location.jpg", "Resources/img/location_hoover.jpg", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(200.f, 100.f)));
	
	/*m_sm_popup = std::make_shared<StateManager>();*/
//	m_popup_buttons.push_back(std::make_unique<gui::ChangeStateButton>("1", "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(150.f, 300.f), m_sm_popup, &NpcView::GetInstance()));
//	m_popup_buttons.push_back(std::make_unique<gui::ChangeStateButton>("2", "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(150.f, 500.f), m_sm_popup, &NpcView::GetInstance()));
	
}

void StateRunning::Clean()
{
	
}

void StateRunning::Pause()
{

}

void StateRunning::Update(sf::Vector2f windowsize)
{
	m_hud->Update(windowsize);
	/*m_sm_view->Update(windowsize);*/

	/*if (!m_sm_popup->IsEmpty())
		m_sm_popup->Update(windowsize);*/
}


void StateRunning::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_hud.get());
	//target.draw(*m_sm_view.get());

	/*if (!m_sm_popup->IsEmpty())
		target.draw(*m_sm_popup.get());*/
	
	//for (auto& button : m_view_buttons)
	//{
	//	target.draw(*button.get());
	//}

	//for (auto& button : m_popup_buttons)
	//{
	//	target.draw(*button.get());
	//}
}

void StateRunning::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	m_hud->HandleEvents(event, mousepos);
	//for (auto& button : m_view_buttons)
	//{
	//	button->HandleEvents(event, mousepos);
	//}

	//for (auto& button : m_popup_buttons)
	//{
	//	button->HandleEvents(event, mousepos);
	//}

	///*m_sm_view->HandleEvents(event, mousepos);*/

	//if (!m_sm_popup->IsEmpty())
	//	m_sm_popup->HandleEvents(event, mousepos);
}

