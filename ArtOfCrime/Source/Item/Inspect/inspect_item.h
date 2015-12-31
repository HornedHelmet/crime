#pragma once
#include <SFML\Graphics.hpp>
#include <string>

// Display detailed information about an item.
class InspectItem :
    public sf::Drawable
{
public:
    InspectItem(std::string name, std::string description, std::string texturepath, float scalex = 1.f, float scaley = 1.f);
    ~InspectItem();

    // Handle events.
    void HandleEvents(sf::Event event);
    
private:
    InspectItem(){}

    // Draw.
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    sf::Font m_font;
    sf::Text m_name;
    sf::Text m_description;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    std::string m_inputstr;
    sf::Text m_inputtext;


};

