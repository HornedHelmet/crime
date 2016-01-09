#pragma once
#include "Actor.h"

class Npc : public Actor
{
public:
    Npc();
    ~Npc();

    // Update this item.
    virtual void Update(float time);

    // Handle user input events.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

private:
    virtual void OnClick();

    virtual void OnMouseOver();

};

