#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>

class Mouse{

public:
    static bool IsMouseOver(const sf::Sprite& sprite, const sf::Vector2i mousepos)
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
};