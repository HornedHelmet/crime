#pragma once
#include "interactable.h"



class Actor : public Interactable 
{
public:
    Actor();
    virtual ~Actor();

    virtual void Update(float time) = 0;

    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos) = 0;

protected:
    sf::Sprite m_sprite;
    sf::Texture m_texture;


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};