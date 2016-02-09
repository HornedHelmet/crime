#pragma once
#include "runnable_drawable.h"
#include "button.h"
#include <vector>

class HUD : public aoc::RunnableDrawable
{

public:
	HUD();
	~HUD();

	virtual void Update(sf::Vector2f windowsize)
	{
		for (auto button : m_button_vector)
		{
			button->Update(windowsize);
		}
	}

	virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos)
	{
		for (auto button : m_button_vector)
		{
			button->HandleEvents(event, mousepos);
		}
	}

	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto button : m_button_vector)
		{
			button->Draw(target, states);
		}
	}


	template<class ReturnType, class Class, class... Params>
	void CreateButton(std::string texture_path, std::string hoover_texture_path,sf::Vector2f scale, sf::Vector2f position, 
		ReturnType(Class::*method_ref)(Params...), Class& class_ref, Params&... param_ref)
	{
		m_button_vector.push_back(
			new Button<ReturnType, Class, Params...>(
				class_ref, method_ref, param_ref...,	  // Class, method, and params called with OnClick event
				texture_path, hoover_texture_path,       // Normal and hoover texture
				scale, position                          // Scale and position
				)
			);
	}

private:
	std::vector<aoc::RunnableDrawable*> m_button_vector;
};

