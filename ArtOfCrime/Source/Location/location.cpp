#include "location.h"
#include "npc.h"
#include "debug.h"

Location::Location() :
	m_showactions(false)
{
	//////////////////////////////////////////
	// Temporary

	m_sprite.setPosition(200, 100);

	if (m_texture.loadFromFile("Resources/img/location.jpg"))
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load m_texture", "location.cpp", "Location");
	}
	m_actions[skill::pickpocket] = 2;

	////////////////////////////////////////
}


Location::~Location()
{
}

void Location::Update(sf::Vector2f windowsize)
{
	if (m_showactions)
	{
		// Update actions
	}
}

void Location::SetOwner(Npc const* owner)
{
	m_owner = owner;
}

void Location::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);

	if (m_showactions)
	{
		// Draw actions 
	}
}

void Location::OnHoover()
{

}

void Location::OnClick()
{
	Debug::Print("Location selected");

	m_showactions = true;

}


void Location::UnHoover()
{

}

void Location::UnClick()
{
	m_showactions = false;
}