#pragma once
#include "runnable.h"
#include "button.h"
#include "npc.h"
#include <SFML\Graphics\Drawable.hpp>
#include <memory>

#include "debug.h"

template <class C, class Tr, class Arg>
class Hud : public Runnable, public sf::Drawable
{
	typedef Tr(C::*OnClickEvent)(Arg);
	// ReturnType (ClassName::*arg)(ParameterList);
public:
	Hud(C& target, OnClickEvent onclick_method) :
		m_target(target),
		m_method(onclick_method)
	{
		//m_button_vec.push_back(std::make_unique<gui::Button<Hud, void, int> >(*this, &Hud::_Button_OnClick_Event_, m_button_vec.size(), "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)));
		//m_button_vec.push_back(std::make_unique<gui::Button<Hud, void, int> >(*this, &Hud::_Button_OnClick_Event_, m_button_vec.size(), "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)));

	}
	~Hud(){}

	virtual void Update(sf::Vector2f windowsize)
	{

	}

	virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos)
	{
		for (auto& button : m_button_vec)
		{
			button.HandleEvents(event, mousepos);
		}
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& button : m_button_vec)
		{
			target.draw(button);
		}
	}

	// Dynamic overload på denna
	void CreateButton(C& state, Arg& actor, OnClickEvent kl)
	{
		m_button_vec.push_back(gui::Button<C, void, Arg&>(state, kl, actor, "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)));
		//m_button_vec.push_back(std::make_unique<gui::Button<C, OnClickEvent, Arg> >(m_target, m_method, arg, "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)));
		//(m_target.*(m_method))(arg);
	}

	// Button
	void _Button_OnClick_Event_(int id)
	{

	}

private:
	//std::unique_ptr<gui::Button<Hud, void, int> > m_button;
	//std::vector<std::unique_ptr<gui::Button<Hud, void, Actor&> > > m_button_vec;
	std::vector<gui::Button<C, void, Actor&> > m_button_vec;

	OnClickEvent m_method;
	C& m_target;

};

