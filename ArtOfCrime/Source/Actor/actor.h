#pragma once
#include "interactable.h"


// Actor class is a base class for all player or AI controlled units in the game
class Actor : public Interactable 
{
public:
	// Constructor
	// TODO: Expand constructor to take texture path etc
    Actor(std::string name, std::string description, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position);

	// Deconstructor
    virtual ~Actor();

	// Update this object.
    virtual void Update(sf::Vector2f windowsize) = 0;

	virtual void Clean() = 0;


protected:
	// Specify how this object should be drawn.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	// Specify what this object should do when the players mouse is hoovering this object. 
	virtual void OnHoover() = 0;

	// Specify what this object should do when clicked.
	virtual void OnClick() = 0;

	// Specifies what the object should do when not hoovered.
	virtual void UnHoover() = 0;

	//Specifies what the object should do when something else is clicked.
	virtual void UnClick() = 0;
};