#pragma once
#include "interactable.h"
#include <SFML\System\Vector2.hpp>
#include <string>

namespace gui 
{
	class Button : public Interactable
	{
	public:
		virtual ~Button();

		// Update this object.
		virtual void Update(sf::Vector2f windowsize);
		
		virtual void Clean();


	protected:
		Button(std::string default_texture, std::string hoover_texture, sf::Vector2f scale = sf::Vector2f(1.f, 1.f), sf::Vector2f position = sf::Vector2f(0.f, 0.f));

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		// Hide default constructor
		// Button() {};

		// Specifies what the object should do when hoovered. 
		virtual void OnHoover();

		// Specifies what the object should do when clicked.
		virtual void OnClick() = 0;

		// Speciefies what the object should do when mouse is no longer over the object.
		virtual void UnHoover();

		// Optional
		virtual void UnClick();


	};
}