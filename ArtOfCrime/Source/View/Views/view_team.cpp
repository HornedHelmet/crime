#include "view_team.h"
#include "view_location.h"
#include "object.h"
#include "texture_data.h"
#include <iostream>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include "debug.h"


ViewTeam::ViewTeam(ViewManager& view_manager, NPC& team_member, std::vector<Location>& locations) :
	m_view_manager(view_manager),
	m_team_member(team_member)
{
    m_gui.CreateFrame(TextureData("Resources/Img/Hud/ally_frame.png", sf::Vector2f(0.8f, 0.8f)), sf::Vector2f(250, 50));

    m_gui.CreateText(m_team_member.GetName(), 30, sf::Vector2f(445, 100), sf::Color::Black, sf::Text::Bold);

    m_gui.CreateText(m_team_member.GetDescription(), 15, sf::Vector2f(300, 300));

    m_gui.CreateSprite(m_team_member.GetPhoto(), sf::Vector2f(260, 75));

    m_gui.CreateButton<void, ViewManager>("Resources/Img/Hud/button_close.png", "Resources/Img/Hud/button_close.png",
        sf::Vector2f(0.05f, 0.05f), sf::Vector2f(550.f, 40.f), &ViewManager::PopView, m_view_manager);

    m_gui.CreateButton<void, ViewManager, NPC&, std::vector<Location>&>("Resources/Img/Hud/mission_button.gif", "Resources/Img/Hud/mission_button.gif",
        sf::Vector2f(0.7f, 0.7f), sf::Vector2f(350.f, 500.f), &ViewManager::ChangeView<ViewLocation, NPC&, std::vector<Location>&>, m_view_manager, team_member, locations);

}


ViewTeam::~ViewTeam()
{

}

void ViewTeam::Update(sf::Vector2f windowsize)
{
	m_gui.Update(windowsize);
}

void ViewTeam::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	m_gui.HandleEvents(event, mousepos);
}

void ViewTeam::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_gui.Draw(target, states);
}