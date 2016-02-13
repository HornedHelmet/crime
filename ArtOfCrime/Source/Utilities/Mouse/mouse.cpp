#include "mouse.h"
#include "debug.h"

bool Mouse::b_hoovering_clickable = false;

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
