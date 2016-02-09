#include "view_team.h"
#include "object.h"
#include <iostream>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include "debug.h"


ViewTeam::ViewTeam(ViewManager& view_manager, AObject& team_member) :
	m_view_manager(view_manager)
{
	m_team_member = dynamic_cast<NPC*>(&team_member);

	if (m_team_member == nullptr)
	{
		Debug::Print(Debug::critical, "Error casting from AObject& to NPC*", "ViewTeam", "ViewTeam");
	}

	if (m_background_texture.loadFromFile("Resources/Img/Hud/ally_frame.png"))
	{
		m_background_sprite.setTexture(m_background_texture);
		m_background_sprite.setScale(0.8f, 0.8f);
		m_background_sprite.setPosition(250, 50);
	}

	if (m_font.loadFromFile("Resources/Font/arial.ttf"))
	{
		m_name.setFont(m_font);
		m_name.setCharacterSize(30);
		m_name.setStyle(sf::Text::Bold);
		m_name.setPosition(300, 100);
		m_name.setColor(sf::Color::Black);
		m_name.setString(m_team_member->GetName());
	}
	
	m_button_exit = new Button<void, ViewManager>(m_view_manager, &ViewManager::PopView, "Resources/Img/Hud/button_close.png", "Resources/Img/Hud/button_close.png", sf::Vector2f(0.05f, 0.05f), sf::Vector2f(550.f, 40.f));
}


ViewTeam::~ViewTeam()
{
}

void ViewTeam::Update(sf::Vector2f windowsize)
{
	//Debug::Print(m_background_sprite.ge);
	m_button_exit->Update(windowsize);
}

void ViewTeam::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	m_button_exit->HandleEvents(event, mousepos);
}

void ViewTeam::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_background_sprite);
	target.draw(m_name);
	target.draw(*m_button_exit);
}