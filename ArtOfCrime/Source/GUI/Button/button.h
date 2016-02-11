#pragma once
#include "runnable_drawable.h"
#include "mouse.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <tuple>



// A class that creates a new button. The button has an onclick event that will call the method wich is supplied
// to the template and through the constuctor. The method can have any return type and any amount of parameters.
// All parameters will be stored inside the button as either a reference or a copy.  
template<class ReturnType, class Class, class... Params>
class Button : public aoc::RunnableDrawable
{
	// Typedef our method pointer. 
	typedef ReturnType(Class::*Method)(Params...);

public:
	// A reference to the method and any parameters that should be used when the button is clicked must be supplied thorugh the constructor. 
	Button(Class& class_ref, Method method, Params&... params_ref, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
			m_class(class_ref), m_method(method), m_params_tuple(std::forward_as_tuple(params_ref...)), // std::forward_as_tuple since we want references.
			b_clicked(false), b_hoovered(false), b_allow_repeat_click(false)
	{
		///////////////////////////////////////////
		// Load texture and setup textures & sprite
		if (m_texture.loadFromFile(default_texture) && m_texture_hoover.loadFromFile(hoover_texture))
		{
			m_sprite.setTexture(m_texture);
			m_sprite.setScale(scale);
		}
		m_sprite.setPosition(position);
		///////////////////////////////////////////
	}

	~Button(){}

	// Method that updates the button each tick.
	void Update(sf::Vector2f windowsize)
	{
		if(b_hoovered)
		{
			Mouse::b_hoovering_clickable = true;
		}
	}

	// A method that checks for user mouse events such as if the button is clicked or hoovered.
	void HandleEvents(sf::Event event, sf::Vector2i mousepos)
	{
		if (Mouse::IsMouseOver(m_sprite, mousepos))
		{
			if (!b_hoovered)
			{
				HooverBegin();
			}

			if ((!b_clicked || b_allow_repeat_click) && Mouse::IsMouseButtonPressed(event, sf::Mouse::Left))
			{
				OnClick();
			}
		}
		else
		{
			if (b_hoovered)
			{
				HooverEnd();
			}
			if (b_clicked && Mouse::IsMouseButtonPressed(event, sf::Mouse::Left))
			{
				UnClick();
			}
		}
	}

	// Draw the button sprite.
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_sprite);
	}

private:
	Button() {};

	// Helper method that expands the tuple back into the variadic parameter and calls the method.
	// How to expand the tuple was explained by:
	// Source: https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
	// Author: Murray Cumming
	template<std::size_t... Is>
	void EventNotify(const std::tuple<Params...>& tuple, std::index_sequence<Is...>)
	{
		(m_class.*m_method)(std::get<Is>(tuple)...);
	}

	// Method for when the users mouse is hoovering the button.
	void Button::HooverBegin()
	{
		b_hoovered = true;
		m_sprite.setTexture(m_texture_hoover);
	}

	// Method when the users mouse stops hoovering the button.
	void Button::HooverEnd()
	{
		b_hoovered = false;
		m_sprite.setTexture(m_texture);
	}

	// Method called when the button is clicked.
	void Button::OnClick()
	{
		EventNotify(m_params_tuple, std::index_sequence_for<Params...>());
		b_clicked = true;
	}

	// Method called when the button was previously clicked but the user now clicked something else.
	// This is in case we would like to disallow repeated clicks..
	void Button::UnClick()
	{
		b_clicked = false;
	}
	

	bool b_clicked;
	bool b_hoovered;
	bool b_allow_repeat_click;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Texture m_texture_hoover;

	Class& m_class;
	Method m_method;
	std::tuple<Params...> m_params_tuple;




};

