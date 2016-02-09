#pragma once
#include <SFML\Graphics\Drawable.hpp>

namespace aoc
{
	// A drawable class that can be rendered to the screen.
	class Drawable : public sf::Drawable
	{
	public:
		// Draw this object
		virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const { Draw(target, states); };
	};
}
