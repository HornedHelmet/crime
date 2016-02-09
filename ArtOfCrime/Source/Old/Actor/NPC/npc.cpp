#include "npc.h"
#include "mouse.h"
#include "debug.h"

Npc::Npc(std::string name, std::string description, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position, std::vector<std::shared_ptr<Location> > const& locations) :
	Actor(name, description, default_texture, hoover_texture, scale, position),
	m_locationvector(locations),
	b_showlocations(false)
{
	m_name = name;
}


Npc::~Npc()
{
}


void Npc::Update(sf::Vector2f windowsize)
{
	if (b_showlocations)
	{
		for (auto& location : m_locationvector)
		{
			location->SetOwner(this);
			location->Update(windowsize);
		}
	}
}

void Npc::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	// Do custom events ? 
	Actor::HandleEvents(event, mousepos);

	if (b_showlocations)
	{
		for (auto& location : m_locationvector)
		{
			location->HandleEvents(event, mousepos);
		}
	}
}

void Npc::Clean()
{
	//b_showlocations = false;
}

void Npc::OnClick()
{
	Debug::Print("NPC selected");
	b_showlocations = true;
}

void Npc::OnHoover()
{

}


void Npc::UnHoover()
{

}


void Npc::UnClick()
{
	b_showlocations = false;
}

void Npc::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Actor::draw(target, states);
	if (b_showlocations)
	{
		for (auto& location : m_locationvector)
		{
			target.draw(*location.get());
		}
	}
}
