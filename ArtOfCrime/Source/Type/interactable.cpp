#include "interactable.h"
#include "mouse.h"
#include "debug.h"

Interactable::Interactable(std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
	b_allow_repeat_click(false),
	b_clicked(false),
	b_hoovered(false)
{
	if (m_texture.loadFromFile(default_texture))
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(scale);
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load m_texture", "interactable.cpp", "Interactable");
	}

	if (!m_texture_hoover.loadFromFile(hoover_texture))
	{
		Debug::Print(Debug::warning, "Failed to load m_texture_hoover", "interactable.cpp", "Interactable");
	}

	m_sprite.setPosition(position);
}


Interactable::~Interactable()
{

}

void Interactable::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	if (Mouse::IsMouseOver(m_sprite, mousepos))
	{
		if (!b_hoovered)
		{
			OnHoover();
			b_hoovered = true;
			Mouse::SetIsHooveringClickable(true);
			m_sprite.setTexture(m_texture_hoover);
		}

		if ((!b_clicked || b_allow_repeat_click) && Mouse::IsMouseButtonPressed(event, sf::Mouse::Left))
		{
			OnClick();
			b_clicked = true;
		}
	}
	else
	{
		if (b_hoovered)
		{
			UnHoover();
			b_hoovered = false;
			Mouse::SetIsHooveringClickable(false);
			m_sprite.setTexture(m_texture);
		}
		if (b_clicked && Mouse::IsMouseButtonPressed(event, sf::Mouse::Left))
		{
			UnClick();
			b_clicked = false;
		}
	}
}
