#include "inspect_item.h"
#include "debug.h"

InspectItem::InspectItem(sf::Sprite& parent, std::string name, std::string description, std::string texture, sf::Vector2f scale) :
	Interactable(texture, texture, scale, sf::Vector2f(0,0)),
	m_parent(parent)
{
    /*if (m_texture.loadFromFile(texturepath))
    {
        m_sprite.setTexture(m_texture);
		m_sprite.setScale(scale);
    }
    else
    {
        Debug::Print(Debug::warning, "Failed to load texture", "inspect_item.cpp", "InspectItem");
    }
*/
    if (m_font.loadFromFile("Resources/font/arial.ttf"))
    {
        m_name = sf::Text(name, m_font);
        m_name.setPosition(sf::Vector2f(0.f, 0.f));

        m_description = sf::Text(description, m_font);
        m_description.setPosition(sf::Vector2f(0.f, 0.f));
    }
    else
    {
        Debug::Print(Debug::warning, "Failed to load font", "inspect_item.cpp", "InspectItem");
    }

    m_inputtext.setFont(m_font);
    m_inputtext.setPosition(sf::Vector2f(0.f, 0.f));
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

void InspectItem::Update(sf::Vector2f windowsize)
{
	// Align sprite in the center of window.
	m_sprite.setPosition(
		windowsize.x / 2 - m_sprite.getGlobalBounds().width / 2, 
		windowsize.y / 2 - m_sprite.getGlobalBounds().height / 2);

	// Align item name above the sprite.
	m_name.setPosition(
		m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2 - m_name.getGlobalBounds().width / 2,
		m_sprite.getPosition().y - m_name.getCharacterSize() - m_name.getGlobalBounds().height);

	// Align description belove the sprite.
	m_description.setPosition(
		m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2 - m_name.getGlobalBounds().width / 2,
		m_sprite.getPosition().y + m_sprite.getGlobalBounds().height);

	// Align input text below description.
	m_inputtext.setPosition(
		m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2 - m_inputtext.getGlobalBounds().width / 2,
		m_sprite.getPosition().y + m_sprite.getGlobalBounds().height + m_inputtext.getGlobalBounds().height + m_name.getGlobalBounds().height);
}

void InspectItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
    target.draw(m_name);
    target.draw(m_description);
    target.draw(m_inputtext);
}

void InspectItem::Clean()
{
}

void InspectItem::OnClick()
{

}

void InspectItem::OnHoover()
{

}

void InspectItem::UnHoover()
{

}

void InspectItem::UnClick()
{

}