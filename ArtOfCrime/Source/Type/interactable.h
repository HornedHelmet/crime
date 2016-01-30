#pragma once
#include "runnable.h"
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderTarget.hpp>

// This class is the base of all objects that can be interacted with in the game.
class Interactable : public Runnable, public sf::Drawable
{
public:
	// Deconstructor
	virtual ~Interactable();

    // Update this object.
    virtual void Update(sf::Vector2f windowsize) = 0;

    // Checks whether the sprite of this object (m_sprite) is pressed or hoovered by the user.
	// If pressed OnClick() method is called, if hoovered OnHoover() is called.
	// Can be overriden for custom event implementation.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	// This is called when the object is not currently in use, such as the user has swapped to a different view.
	// The object should not be destroyed but it should reset to a state where nothing is selected but user input may be saved.
	virtual void Clean() = 0;
	
protected:
	// Constructor available for children.
	Interactable(std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position);

	// Specify how the class should be drawn (inherited from Drawable).
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Texture m_texture_hoover;

	bool b_allow_repeat_click;

private:

	// Specifies what the object should do when hoovered. 
	virtual void OnHoover() = 0;

	// Specifies what the object should do when not hoovered.
	virtual void UnHoover() = 0;

	// Specifies what the object should do when clicked.
	virtual void OnClick() = 0;

	//Specifies what the object should do when something else is clicked.
	virtual void UnClick() = 0;

	bool b_clicked;
	bool b_hoovered;
	
};