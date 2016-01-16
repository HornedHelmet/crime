#include "interactable.h"
#include "mouse.h"

void Interactable::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	if (Mouse::IsMouseOver(m_sprite, mousepos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			OnClick();
		}
		else
		{
			OnHoover();
		}
	}
}