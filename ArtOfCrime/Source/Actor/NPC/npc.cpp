#include "npc.h"
#include "mouse.h"
#include "debug.h"

Npc::Npc(std::vector<std::shared_ptr<Location> > const& locations) :
	m_locationvector(locations),
	b_showlocations(false)
{

}


Npc::~Npc()
{
}


void Npc::Update(float time)
{
	if (b_showlocations)
	{
		for (auto& location : m_locationvector)
		{
			location->SetOwner(this);
			location->Update(time);
		}
	}
}

void Npc::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	Actor::HandleEvents(event, mousepos);

	if (b_showlocations)
	{
		for (auto& location : m_locationvector)
		{
			location->HandleEvents(event, mousepos);
		}
	}
}

void Npc::OnClick()
{
	Debug::Print("NPC selected");
	b_showlocations = true;
}

void Npc::OnHoover()
{

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
