#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Event.hpp>
#include <map>

class Interactable;

class Mouse{

public:
	// Checks if the mouse is hoovering the given sprite.
	static bool IsMouseOver(const sf::Sprite& sprite, const sf::Vector2i mousepos);

	// Checks if the given mouse button is pressed. ( The SFML function is bugged).
	static bool IsMouseButtonPressed(sf::Event event, sf::Mouse::Button button);

	static bool IsHooveringClickable();
	
	static void SetIsHooveringClickable(Interactable const* interactable, bool hoovering);


private:
	static bool b_hoovering_clickable;
	static std::map<Interactable const*, bool> m_hoovering_interactable;

};

