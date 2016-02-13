#include "view_team.h"
#include "object.h"
#include <iostream>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include "debug.h"


ViewTeam::ViewTeam(ViewManager& view_manager, NPC& team_member) :
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
		m_name.setFont(m_font);
		m_name.setCharacterSize(30);
		m_name.setStyle(sf::Text::Bold);
		m_name.setPosition(300, 100);
		m_name.setColor(sf::Color::Black);
		m_name.setString(m_team_member.GetName());
	}
	
	m_gui.CreateButton<void, ViewManager>("Resources/Img/Hud/button_close.png", "Resources/Img/Hud/button_close.png", sf::Vector2f(0.05f, 0.05f), sf::Vector2f(550.f, 40.f), &ViewManager::PopView, m_view_manager);

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
	target.draw(m_name);

	m_gui.Draw(target, states);
}