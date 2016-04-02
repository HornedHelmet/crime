#include "view_team.h"
#include "view_location.h"
#include "object.h"
#include <iostream>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include "debug.h"


ViewTeam::ViewTeam(ViewManager& view_manager, NPC& team_member, std::vector<Location>& locations) :
	m_view_manager(view_manager),
	m_team_member(team_member)
{

	if (m_ally_texture.loadFromFile("Resources/Img/Hud/ally_frame.png"))
	{
		m_ally_sprite.setTexture(m_ally_texture);
		m_ally_sprite.setScale(0.8f, 0.8f);
		m_ally_sprite.setPosition(250, 50);
	}

	if (m_background_texture.loadFromFile("Resources/Img/Hud/grey_bg.png"))
	{
		m_background_sprite.setTexture(m_background_texture);
		m_background_sprite.setColor(sf::Color(255, 255, 255, 125));
	}

	if (m_font.loadFromFile("Resources/Font/arial.ttf"))
	{
        m_team_member.GetName().setFont(m_font);
        m_team_member.GetName().setCharacterSize(30);
        m_team_member.GetName().setStyle(sf::Text::Bold);
        m_team_member.GetName().setPosition(445, 100);
        m_team_member.GetName().setColor(sf::Color::Black);

        m_team_member.GetDescription().setFont(m_font);
        m_team_member.GetDescription().setCharacterSize(15);
        m_team_member.GetDescription().setPosition(300, 300);
        m_team_member.GetDescription().setColor(sf::Color::Black);
	}

    m_team_member.GetPhoto().setPosition(260, 75);
	
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
	target.draw(m_background_sprite);
	target.draw(m_ally_sprite);
    target.draw(m_team_member.GetPhoto());
	target.draw(m_team_member.GetName());
    target.draw(m_team_member.GetDescription());

	m_gui.Draw(target, states);
}