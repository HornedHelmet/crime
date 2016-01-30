#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Event.hpp>

class Mouse{

public:
	// Checks if the mouse is hoovering the given sprite.
	static bool IsMouseOver(const sf::Sprite& sprite, const sf::Vector2i mousepos);

	// Checks if the given mouse button is pressed. ( The SFML function is bugged).
	static bool IsMouseButtonPressed(sf::Event event, sf::Mouse::Button button);

	static bool IsHooveringClickable();
	
	static void SetIsHooveringClickable(bool hoovering);

	static void NewTick();


private:
	static bool b_hoovering_clickable;
	
	static bool b_hoovering_clickable_this_tick;

};

