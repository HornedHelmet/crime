#pragma once
#include <SFML\Graphics.hpp>

// This class is the base of all objects that can be interacted with in the game.
class Interactable : public sf::Drawable
{
public:
    // Update this object.
    virtual void Update(float time) = 0;

    // Handle user input events.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);
	
protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

private:
    // Specify how the class should be drawn (inherited from Drawable).
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	// Specifies what the object should do when hoovered. 
	virtual void OnHoover() = 0;

	// Specifies what the object should do when clicked.
	virtual void OnClick() = 0;
};