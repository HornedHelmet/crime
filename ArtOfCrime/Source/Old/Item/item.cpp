#include "item.h"
#include "mouse.h"
#include "debug.h"

Item::Item(std::string name, std::string description, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
	Interactable(default_texture, hoover_texture, scale, position),
    m_name(name),
    m_description(description)
{
	//if (m_texture.loadFromFile(texturepath))
	//{
	//	m_sprite.setTexture(m_texture);
	//	m_sprite.setScale(sf::Vector2f(scale, scale));
	//}
	//else
	//{
	//	Debug::Print(Debug::warning, "Failed to load m_texture", "item.cpp", "Item");
	//}

	//m_sprite.setPosition(posx, posy);
	b_allow_repeat_click = true;
}

Item::Item(std::string name, std::string description, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position,
		   std::string inspect_texture, sf::Vector2f inspect_scale) :
	Interactable(default_texture, hoover_texture, scale, position),
	m_name(name),
	m_description(description)
{
	//if (m_texture.loadFromFile(texturepath))
	//{
	//	m_sprite.setTexture(m_texture);
	//	m_sprite.setScale(sf::Vector2f(scale, scale));
	//}
	//else
	//{
	//	Debug::Print(Debug::warning, "Failed to load m_texture", "item.cpp", "Item");
	//}
	//m_sprite.setPosition(posx, posy);

	m_detailed = std::make_unique<InspectItem>(m_sprite, name, description, inspect_texture, inspect_scale);
	b_allow_repeat_click = true;
}

void Item::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	Interactable::HandleEvents(event, mousepos);

    if (m_detailed)
    {
        m_detailed->HandleEvents(event, mousepos);
    }

	/*else
	{
		Interactable::HandleEvents(event, mousepos);
	}*/

}

void Item::Update(sf::Vector2f windowsize)
{
	if (m_detailed)
	{
		m_detailed->Update(windowsize);
	}
}

void Item::Clean()
{
	Interactable::Clean();
	if (m_detailed)
	{
		m_detailed->Hide();
	}
}

void Item::OnClick()
{
	if (m_detailed)
	{
		if (m_detailed->IsShown())
		{
			m_detailed->Hide();
		}
		else
		{
			m_detailed->Show();
		}
	}
}

void Item::OnHoover()
{
    // TODO
}

void Item::UnHoover()
{

}

void Item::UnClick()
{
	if (m_detailed)
	{
		m_detailed->Hide();
	}
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
    
	if (m_detailed)
    {
        target.draw(*m_detailed);
    }
}