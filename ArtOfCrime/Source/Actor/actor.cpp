#include "actor.h"
#include "debug.h"

Actor::Actor()
{

	//////////////////////////////////////////
	// Temporary
	m_sprite.setPosition(400, 100);

    if (m_texture.loadFromFile("Resources/detective.gif"))
    {
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
    }
    else
    {
        Debug::Print(Debug::warning, "Failed to load m_texture", "actor.cpp", "Actor");
    }
	//////////////////////////////////////////

}

Actor::~Actor()
{

}


void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
}