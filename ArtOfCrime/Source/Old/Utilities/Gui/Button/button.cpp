//#include "button.h"
//#include "debug.h"
//#include "mouse.h"
//using namespace gui;
//
//
//template <class C, class Tr>
//Button<C, Tr>::Button(C& target, eventMethod method) : // , std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
//	Interactable(default_texture, hoover_texture, scale, position),
//	m_target(taget), 
//	m_method(method)
//{
//
//}
//
////Button::Button(std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position) :
////	Interactable(default_texture, hoover_texture, scale, position)
////{
////	/*if (m_texture.loadFromFile(texturepath))
////	{
////		m_sprite.setTexture(m_texture);
////		m_sprite.setScale(scale);
////	}
////	else
////	{
////		Debug::Print(Debug::warning, "Failed to load m_texture", "button.cpp", "Button");
////	}
////
////	m_sprite.setPosition(position);*/
////}
////
////Button::~Button()
////{
////
////}
//
//template <class C, class Tr>
//void Button<C, Tr>::Clean()
//{
//
//}
//
//template <class C, class Tr>
//void Button<C, Tr>::Update(sf::Vector2f windowsize)
//{
//
//}
//
//template <class C, class Tr>
//void Button<C, Tr>::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	target.draw(m_sprite);
//}
//
//
//template <class C, class Tr>
//void Button<C, Tr>::OnClick()
//{
//	(m_target.*(m_method))();
//}
//
//template <class C, class Tr>
//void Button<C, Tr>::OnHoover()
//{
//	// set outline
//}
//
//template <class C, class Tr>
//void Button<C,Tr>::UnHoover()
//{
//	// remove outline
//}
//
//template <class C, class Tr>
//void Button<C,Tr>::UnClick()
//{
//	//Debug::Print("unclick");
//}
////
