#pragma once
#include "runnable_drawable.h"
#include "mouse.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <tuple>




template<class ReturnType, class Class, class... Params>
class Button : public aoc::RunnableDrawable
{
	typedef ReturnType(Class::*Method)(Params...);

public:
	Button(Class& class_ref, Method method, Params&... params_ref, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
		m_class(class_ref),
		m_method(method),
		m_params_tuple(std::forward_as_tuple(params_ref...)) // std::make_tuple as forward_as_tuple so it can handle references
	{

		if (m_texture.loadFromFile(default_texture) && m_texture_hoover.loadFromFile(hoover_texture))
		{
			m_sprite.setTexture(m_texture);
			m_sprite.setScale(scale);
		}

		m_sprite.setPosition(position);
	}

	~Button(){}

	// Update this object.
	void Update(sf::Vector2f windowsize)
	{
		if(b_hoovered)
		{
			Mouse::b_hoovering_clickable = true;
		}
	}

	// Handle user events for this object.
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


	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_sprite);
	}

private:

	void Button::HooverBegin()
	{
		b_hoovered = true;
		m_sprite.setTexture(m_texture_hoover);
	}


	void Button::HooverEnd()
	{
		b_hoovered = false;
		m_sprite.setTexture(m_texture);
	}


	void Button::OnClick()
	{
		EventNotify(m_params_tuple, std::index_sequence_for<Params...>());
		b_clicked = true;
	}

	void Button::UnClick()
	{
		b_clicked = false;
	}

	
	// Helper method that expands the tuple and calls the method.
	// Source: https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
	// Author: Murray Cumming
	template<std::size_t... Is>
	void EventNotify(const std::tuple<Params...>& tuple, std::index_sequence<Is...>)
	{
		(m_class.*m_method)(std::get<Is>(tuple)...);
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

