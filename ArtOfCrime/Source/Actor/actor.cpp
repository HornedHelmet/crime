#include "actor.h"
#include "debug.h"

Actor::Actor(std::string name, std::string description, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
	Interactable(default_texture, hoover_texture, scale, position)
{

	//////////////////////////////////////////
	// Temporary
	/*m_sprite.setPosition(400, 100);

    if (m_texture.loadFromFile("Resources/img/detective.gif"))
    {
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
    }
    else
    {
        Debug::Print(Debug::warning, "Failed to load m_texture", "actor.cpp", "Actor");
    }*/
	//////////////////////////////////////////

}

Actor::~Actor()
{

}


void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
}