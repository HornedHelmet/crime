#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Event.hpp>

class Runnable
{
public:
	// Update this object.
	virtual void Update(sf::Vector2f windowsize) = 0;

	// Handle user events for this object.
	virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos) = 0;

};

