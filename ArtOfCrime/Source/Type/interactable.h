#pragma once
#include <SFML\Graphics.hpp>

class Interactable : public sf::Drawable
{
public:
    // Update this item.
    virtual void Update(float time) = 0;

    // Handle user input events.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos) = 0;

private:
    // Specify how the class should be drawn (inherited from Drawable).
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};