#include "item.h"
#include "mouse.h"
#include "debug.h"

Item::Item(std::string name, std::string description, std::string texturepath, float scale, float posx, float posy) :
    m_name(name),
    m_description(description),
    b_inspected(false),
	b_caninspect(false)
{
	if (m_texture.loadFromFile(texturepath))
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(sf::Vector2f(scale, scale));
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load m_texture", "item.cpp", "Item");
	}

	m_sprite.setPosition(posx, posy);
}

Item::Item(std::string name, std::string description, std::string texturepath, float scale, float posx, float posy,
		   std::string inspecttexturepath, float inspectscale) :
	m_name(name),
	m_description(description),
	b_inspected(false),
	b_caninspect(true)
{
	if (m_texture.loadFromFile(texturepath))
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(sf::Vector2f(scale, scale));
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load m_texture", "item.cpp", "Item");
	}

	m_sprite.setPosition(posx, posy);
	m_detailed = std::make_unique<InspectItem>(m_sprite, name, description, inspecttexturepath, inspectscale);

}

void Item::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	Interactable::HandleEvents(event, mousepos);
    
    if (b_inspected)
    {
        m_detailed->HandleEvents(event, mousepos);
    }

}

void Item::Update(float time)
{
	if (b_caninspect)
	{
		m_detailed->Update(time);
	}
}

void Item::OnClick()
{
    b_inspected = !b_inspected;
}

void Item::OnHoover()
{
    // TODO
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
    if (b_caninspect && b_inspected)
    {
        target.draw(*m_detailed);
    }
}