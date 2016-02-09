#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Event.hpp>

namespace aoc
{
	// A runnable class that can be updated and can handle user events.
	class Runnable
	{
	public:
		// Update this object.
		virtual void Update(sf::Vector2f windowsize) = 0;

		// Handle user events for this object.
		virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos) = 0;
	};
}



