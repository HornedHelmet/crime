#pragma once

#include "inspect_item.h"
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>

class Item : 
    public sf::Drawable{

public:

    Item(std::string name, std::string description, float posx = 0.f, float posy = 0.f);

    virtual ~Item(){}

    // TODO: Update this item.
    void Update(float time);

    // Handle input events.
    void HandleEvents(sf::Event event);

    // Method that is called when the player clicks on the Item-
    virtual void OnClick();

    // Method that is called when the players mouse is over the item.
    virtual void OnMouseOver();

    // Get the sprite of the Item.
    sf::Sprite& GetSprite() { return m_sprite; }

protected:
    // The InspectItem view for this Item. 
    // This object should display advanced information about this Item.
    std::unique_ptr<InspectItem> m_detailed;

    // This Items texture.
    sf::Texture m_texture;

    // This Items sprite.
    sf::Sprite m_sprite;

private:
    Item(){};
    
    // Defines what should be rendered to the screen for this Item. 
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Name of the item.
    const std::string m_name;

    // Description of the Item.
    const std::string m_description;

    // If the player is trying to inspect the item.
    bool b_inspected;








};