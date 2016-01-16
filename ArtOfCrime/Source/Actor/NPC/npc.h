#pragma once
#include "Actor.h"
#include "location.h"
#include <memory>

// Class for creating new npc actors.
class Npc : public Actor
{
public:
	// Constructor. Reference to a vector of available locations will be saved.
    Npc(std::vector<std::shared_ptr<Location> > const& locations);

	// Deconstructor
    ~Npc();

    // Update this object.
    virtual void Update(float time);

    // Handle user input events.
     virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);


private:
	// Specifies how to draw this object
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Specifies what the npc should do when hoovered. 
	virtual void OnHoover();

	// Specifies what the npc should do when clicked.
	virtual void OnClick();

	bool b_showlocations;

	std::vector<std::shared_ptr<Location> > const& m_locationvector;

};

