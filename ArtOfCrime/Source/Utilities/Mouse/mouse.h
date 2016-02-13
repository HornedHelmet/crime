#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Event.hpp>
#include <map>

// All things mouse related.
class Mouse{

public:
	// Checks if the mouse is hoovering the given sprite.
	static bool IsMouseOver(const sf::Sprite& sprite, const sf::Vector2i mousepos);

	// Checks if the given mouse button is pressed. ( The SFML lib function is bugged, use this instead ).
	static bool IsMouseButtonPressed(sf::Event event, sf::Mouse::Button button);

	// Indicates if the cursor is hoovering a clickable object.
	static bool b_hoovering_clickable;

private:

};

