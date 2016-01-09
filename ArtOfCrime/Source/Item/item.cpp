#include "item.h"
#include "mouse.h"
#include "debug.h"

Item::Item(std::string name, std::string description, float posx, float posy) :
    m_name(name),
    m_description(description),
    b_inspected(false)
{
    m_sprite.setPosition(posx, posy);
}

void Item::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{

    if (Mouse::IsMouseOver(m_sprite, mousepos))
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
    
    if (b_inspected)
    {
        m_detailed->HandleEvents(event, mousepos);
    }

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