#pragma once
#include "interactable.h"
#include <SFML\Graphics.hpp>
#include <string>

// Show a more detailed view of a item.
class InspectItem :
    public Interactable
{
public:
	// Constructor
    InspectItem(sf::Sprite& parent, std::string name, std::string description, std::string texturepath, float scale = 1.f);

	// Deconstructor
    ~InspectItem();

	// Handle user input events.
    void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	// Update this
	void Update(float time);
    
private:
	// Hide default constructor
    InspectItem(){}

    // Draw this object.
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Specifies what the object should do when clicked.
	virtual void OnClick();

	// Specifies what the object should do when hoovered. 
	virtual void OnHoover();


    sf::Font m_font;
    sf::Text m_name;
    sf::Text m_description;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
	sf::Sprite const m_parent;

    std::string m_inputstr;
    sf::Text m_inputtext;


};

