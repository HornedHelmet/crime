#include "inspect_item.h"
#include <iostream>

InspectItem::InspectItem(std::string name, std::string description, std::string texturepath, float scalex, float scaley)
{
    if (m_texture.loadFromFile(texturepath))
    {
        m_sprite.setTexture(m_texture);
    }
    else
    {
        std::cout << "Warning: Failed to load texture " << 
            texturepath << " @ inspect_item.cpp : InspectItem(std::string, std::string, std::string)" << std::endl;
    }

    if (m_font.loadFromFile("Resources/arial.ttf"))
    {
        m_name = sf::Text("Map of bank", m_font);
        m_name.setPosition(sf::Vector2f(200.f, 0.f));

        m_description = sf::Text("This is a map over the bank....", m_font);
        m_description.setPosition(sf::Vector2f(150.f, 400.f));
    }
    else
    {
        std::cout << "Warning: Failed to load font @ inspect_item.cpp : InspectItem(std::string, std::string, std::string)" << std::endl;
    }

    m_sprite.setScale(scalex, scaley);

    m_inputtext.setFont(m_font);
    m_inputtext.setPosition(sf::Vector2f(200.f, 500.f));
}

InspectItem::~InspectItem()
{
}

void InspectItem::HandleEvents(sf::Event event)
{
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

void InspectItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
    target.draw(m_name);
    target.draw(m_description);
    target.draw(m_inputtext);
}