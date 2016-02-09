#pragma once
#include "interactable.h"
#include <SFML\System\Vector2.hpp>
#include <string>

namespace gui 
{
	template <class C, class Tr, class Arg>
	class Button : public Interactable
	{
	public:
		typedef Tr(C::*OnClickEvent)(Arg&);

		Button(C& target, OnClickEvent onclick_method, Arg& arg, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
			Interactable(default_texture, hoover_texture, scale, position), m_target(target), m_method(onclick_method), m_arg(arg){}
		~Button() {};



		// Update this object.
		void Update(sf::Vector2f windowsize){}
		

		//
		void Clean(){}

	protected:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const{ target.draw(m_sprite); }


	private:

		// Specifies what the object should do when hoovered. 
		void OnHoover(){}

		// Specifies what the object should do when clicked.

		void OnClick(){ (m_target.*(m_method))(m_arg); }
			
		 //Speciefies what the object should do when mouse is no longer over the object.
		void UnHoover(){}

		// Optional
		void UnClick(){}

	private:
		OnClickEvent m_method;
		C& m_target;
		Arg& m_arg;


	};
}

