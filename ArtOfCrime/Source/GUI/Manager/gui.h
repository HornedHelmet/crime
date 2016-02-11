#pragma once
#include "runnable_drawable.h"
#include "button.h"
#include <vector>
#include <memory>

// The gui class instantiated by all classes that want to use any sort of gui element, excluding their own sprite, texture and the likes.
// The class acts as a container and will update and render all elements created with a instance of this class.
class GUI : public aoc::RunnableDrawable
{

public:
	GUI() {};
	~GUI() {};

	// Update all gui elements.
	virtual void Update(sf::Vector2f windowsize)
	{
		for (auto& gui_element : m_gui_elements)
		{
			gui_element->Update(windowsize);
		}
	}

	// Handle user input events for all gui elements.
	virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos)
	{
		for (auto& gui_element : m_gui_elements)
		{
			gui_element->HandleEvents(event, mousepos);
		}
	}

	// Render all gui elements.
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& gui_element : m_gui_elements)
		{
			gui_element->Draw(target, states);
		}
	}

	// Create a new button. The supplied method will be bound to the button, and when clicked the button will call the method.
	template<class ReturnType, class Class, class... Params>
	void CreateButton(std::string texture_path, std::string hoover_texture_path,sf::Vector2f scale, sf::Vector2f position, 
		ReturnType(Class::*method_ref)(Params...), Class& class_ref, Params&... param_ref)
	{
		m_gui_elements.push_back(
			std::make_unique<Button<ReturnType, Class, Params...> >(
				class_ref, method_ref, param_ref...,	              // Class, method, and params called with OnClick event
				texture_path, hoover_texture_path,                    // Normal and hoover texture
				scale, position));                                    // Scale and position			
	}



private:
	// Stack storing the gui elements inheriting RunnableDrawable.
	std::vector<std::unique_ptr<aoc::RunnableDrawable> > m_gui_elements;
};

