#include "mouse.h"
#include "interactable.h"
#include "debug.h"

bool Mouse::b_hoovering_clickable = false;
std::map<Interactable const*, bool> Mouse::m_hoovering_interactable;

bool Mouse::IsMouseOver(const sf::Sprite& sprite, const sf::Vector2i mousepos)
{
	if (mousepos.x > sprite.getPosition().x &&
		mousepos.x < sprite.getPosition().x + sprite.getTextureRect().width * sprite.getScale().x &&
		mousepos.y > sprite.getPosition().y &&
		mousepos.y < sprite.getPosition().y + sprite.getTextureRect().height * sprite.getScale().y
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mouse::IsMouseButtonPressed(sf::Event event, sf::Mouse::Button button)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == button)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mouse::IsHooveringClickable()
{
	for (auto& interactable : m_hoovering_interactable)
	{
		if (interactable.second)
		{
			return true;
		}
	}

	return false;
}

void Mouse::SetIsHooveringClickable(Interactable const* interactable, bool hoovering)
{
	m_hoovering_interactable[interactable] = hoovering;
	//if (hoovering)
	//{
	//	m_hoovering_count++;
	//}
	//else
	//{
	//	m_hoovering_count--;
	//}

	//if (m_hoovering_count == 0)
	//{
	//	b_hoovering_clickable = false;
	//}
	//else
	//{
	//	b_hoovering_clickable = true;
	//}
}

