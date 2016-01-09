#include "npc.h"
#include "mouse.h"
#include "debug.h"

Npc::Npc()
{
    Debug::Print("NPC created");
}


Npc::~Npc()
{
}


void Npc::Update(float time)
{

}


void Npc::HandleEvents(sf::Event event, sf::Vector2i mousepos)
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
}

void Npc::OnClick()
{
    Debug::Print("NPC selected");
}

void Npc::OnMouseOver()
{

}