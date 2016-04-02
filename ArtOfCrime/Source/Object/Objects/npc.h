#pragma once
#include "object.h"
#include "texture_data.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Text.hpp>
#include <string>

class NPC : public AObject
{
public:
	NPC(std::string name, std::string description, TextureData texture_data)
	{
        m_name.setString(name);
        m_description.setString(description);

        if (m_texture_photo.loadFromFile(texture_data.path))
        {
            m_sprite_photo.setTexture(m_texture_photo);
            m_sprite_photo.setScale(texture_data.scale);
        }
	}

    sf::Text& GetName()
	{
		return m_name;
	}

     sf::Text& GetDescription()
     {
         return m_description;
     }

     sf::Sprite& GetPhoto()
     {
         return m_sprite_photo;
     }

private:
	sf::Text m_name;
    sf::Text m_description;
    sf::Texture m_texture_photo;
    sf::Sprite m_sprite_photo;
};