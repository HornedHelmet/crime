#include "button.h"
#include "debug.h"
using namespace gui;

Button::Button() :
	m_clicked(false),
	m_hoovered(false)
{
	m_texture.loadFromFile("Resources/img/button.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(0.2f, 0.2f);

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

void Button::OnClick()
{
	m_clicked = true;
	Debug::Print("clicked");
}

void Button::OnHoover()
{
	m_hoovered = true;
}


void Button::UnHoover()
{
	m_hoovered = false;
}

void Button::UnClick()
{
	//m_clicked = false;
}