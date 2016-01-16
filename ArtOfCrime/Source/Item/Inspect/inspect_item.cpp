#include "inspect_item.h"
#include "debug.h"

InspectItem::InspectItem(sf::Sprite& parent, std::string name, std::string description, std::string texturepath, float scale) :
	m_parent(parent)
{
    if (m_texture.loadFromFile(texturepath))
    {
        m_sprite.setTexture(m_texture);
    }
    else
    {
        Debug::Print(Debug::warning, "Failed to load texture", "inspect_item.cpp", "InspectItem");
    }

    if (m_font.loadFromFile("Resources/arial.ttf"))
    {
        m_name = sf::Text(name, m_font);
        m_name.setPosition(sf::Vector2f(200.f, 0.f));

        m_description = sf::Text(description, m_font);
        m_description.setPosition(sf::Vector2f(150.f, 400.f));
    }
    else
    {
        Debug::Print(Debug::warning, "Failed to load font", "inspect_item.cpp", "InspectItem");
    }

    m_sprite.setScale(scale, scale);

    m_inputtext.setFont(m_font);
    m_inputtext.setPosition(sf::Vector2f(200.f, 500.f));
}

InspectItem::~InspectItem()
{
}

void InspectItem::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	Interactable::HandleEvents(event, mousepos);

    if (event.type == sf::Event::TextEntered)
    {
        // Handle ASCII characters only
        if (event.text.unicode < 128)
        {
            m_inputstr += static_cast<char>(event.text.unicode);
            m_inputtext.setString(m_inputstr);
        }
    }
}

void InspectItem::Update(float time)
{
	m_sprite.setPosition(m_parent.getPosition());
	//m_inputtext.set...
}

void InspectItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
    target.draw(m_name);
    target.draw(m_description);
    target.draw(m_inputtext);
}

void InspectItem::OnClick()
{

}

void InspectItem::OnHoover()
{

}