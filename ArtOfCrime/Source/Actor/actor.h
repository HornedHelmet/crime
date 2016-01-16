#pragma once
#include "interactable.h"


// Actor class is a base class for all player or AI controlled units in the game
class Actor : public Interactable 
{
public:
	// Constructor
	// TODO: Expand constructor to take texture path etc
    Actor();

	// Deconstructor
    virtual ~Actor();

	// Update this object.
    virtual void Update(float time) = 0;


protected:
	// Specify how this object should be drawn.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	// Specify what this object should do when the players mouse is hoovering this object. 
	virtual void OnHoover() = 0;

	// Specify what this object should do when clicked.
	virtual void OnClick() = 0;
};