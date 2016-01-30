#pragma once
#include "interactable.h"
#include "action_map.h"
//#include "npc.h"

class Npc;

// This class can be used to create new locations and interact with them.
class Location : public Interactable
{
public:
	// Constructor
	Location(std::string name, std::string description, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position);

	// Deconstructor
	virtual ~Location();

	// Update this object.
	virtual void Update(sf::Vector2f windowsize);

	virtual void Clean(); 

	// Set the owner of this object. The owner is used to determine what actor is
	// trying to interact with this location.
	void SetOwner(Npc const* owner);

private:
	// Specifies how this object is drawn.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Specifies what the object should do when hoovered. 
	virtual void OnHoover();

	// Specifies what the object should do when clicked.
	virtual void OnClick();

	// Specifies what the object should do when not hoovered.
	virtual void UnHoover();

	//Specifies what the object should do when something else is clicked.
	virtual void UnClick();

	// A map of available actions at this location.
	ActionMap m_actions;

	// Pointer to the ownder of this location.
	Npc const* m_owner;

	bool m_showactions;

};

