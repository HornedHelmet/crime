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
    InspectItem(sf::Sprite& parent, std::string name, std::string description, std::string texture, sf::Vector2f scale);

	// Deconstructor
    ~InspectItem();

	// Handle user input events.
    void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	// Update this
	void Update(sf::Vector2f windowsize);

	void Show();

	void Hide();

	bool IsShown() { return b_show; };

    
private:
	// Hide default constructor
	// InspectItem() {};

    // Draw this object.
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Specifies what the object should do when clicked.
	virtual void OnClick();

	// Specifies what the object should do when hoovered. 
	virtual void OnHoover();

	// Specifies what the object should do when not hoovered.
	virtual void UnHoover();

	//Specifies what the object should do when something else is clicked.
	virtual void UnClick();


    sf::Font m_font;
    sf::Text m_name;
    sf::Text m_description;
	sf::Sprite const m_parent;

    std::string m_inputstr;
    sf::Text m_inputtext;

	bool b_show;


};

