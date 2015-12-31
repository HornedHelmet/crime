#include "item.h"


Item::Item(std::string name, std::string description, float posx, float posy) :
    m_name(name),
    m_description(description),
    b_inspected(false)
{
    m_sprite.setPosition(posx, posy);
}

void Item::HandleEvents(sf::Event event)
{

    sf::Vector2i position = sf::Mouse::getPosition();
    if (m_sprite.getTextureRect().contains(position))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            OnClick();
        }
        else
        {
            OnMouseOver();
        }
    }  
    
    m_detailed->HandleEvents(event);
}

void Item::OnClick()
{
    b_inspected = !b_inspected;
}

void Item::OnMouseOver()
{
    // TODO
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
    if (b_inspected)
    {
        target.draw(*m_detailed);
    }
}