#pragma once
#include "Actor.h"
#include "location.h"
#include <memory>

// Class for creating new npc actors.
class Npc : public Actor
{
public:
	// Constructor. Reference to a vector of available locations will be saved.
    Npc(std::string name, std::string description, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position, std::vector<std::shared_ptr<Location> > const& locations);

	// Deconstructor
    ~Npc();

    // Update this object.
    virtual void Update(sf::Vector2f windowsize);

    // Handle user input events.
     virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	 virtual void Clean();

	 std::string Name() { return m_name; }

private:
	// Specifies how to draw this object
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Specifies what the npc should do when hoovered. 
	virtual void OnHoover();

	// Specifies what the npc should do when clicked.
	virtual void OnClick();

	// Specifies what the object should do when not hoovered.
	virtual void UnHoover();

	//Specifies what the object should do when something else is clicked.
	virtual void UnClick();

	bool b_showlocations;

	std::vector<std::shared_ptr<Location> > const& m_locationvector;

	std::string m_name;

};

