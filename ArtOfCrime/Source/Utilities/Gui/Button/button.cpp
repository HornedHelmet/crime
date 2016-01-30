#include "button.h"
#include "debug.h"
#include "mouse.h"

using namespace gui;

Button::Button(std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
	Interactable(default_texture, hoover_texture, scale, position)
{
	/*if (m_texture.loadFromFile(texturepath))
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(scale);
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load m_texture", "button.cpp", "Button");
	}

	m_sprite.setPosition(position);*/
}

Button::~Button()
{

}

void Button::Update(sf::Vector2f windowsize)
{

}
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}

void Button::Clean()
{

}

void Button::OnHoover()
{
	// set outline
}


void Button::UnHoover()
{
	// remove outline
}

void Button::UnClick()
{
	//Debug::Print("unclick");
}

