#pragma once

#include "inspect_item.h"
#include "interactable.h"
#include <memory>
#include <string>

// This class aids in creating new items.
class Item : public Interactable
{

public:
	
	// Constructor for a item that is not inspectable.
	Item(std::string name, std::string description, std::string texturepath, float scale = 1.f, float posx = 0.f, float posy = 0.f);

	// Constructor for a item that is inspectable, i.e. the user can get a more detailed description by hoovering / clicking the item.
    Item(std::string name, std::string description, std::string texturepath, float scale, float posx, float posy, 
		 std::string inspecttexturepath, float inspectscale = 1.f);

	// Deconstructor
    virtual ~Item(){}

    // Update this item.
    void Update(float time);

    // Handle input events.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

    // Get the sprite of the Item.
    sf::Sprite& GetSprite() { return m_sprite; }

protected:
    // The InspectItem view for this Item. 
    // This object should display advanced information about this Item.
    std::unique_ptr<InspectItem> m_detailed;

private:
	// Hide default constructor
    Item() : b_caninspect(false){};
    
    // Specifies how this item should be drawn.
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Specifies what the object should do when clicked.
	virtual void OnClick();

	// Specifies what the object should do when hoovered. 
	virtual void OnHoover();

    // Name of the item.
    const std::string m_name;

    // Description of the Item.
    const std::string m_description;

    // If the player is trying to inspect the item.
    bool b_inspected;

	// If the player can inspect the item.
	bool const b_caninspect;








};