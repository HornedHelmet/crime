//#include "hud.h"
//
//
//
//Hud::Hud(C& target, OnClickEvent method)
//{
//
//	//"Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)
//	//m_button = new gui::Button<Hud, void, int>(*this, &Hud::test, 1, "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)); // gui::Button<class, void>
//	//m_button_vector.push_back(new gui::Button<Hud, void, int>(*this, &Hud::test, m_button_vector.size(), "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)));
//	//m_button_vector.push_back()
//	//std::make_unique<gui::Button<this, &Hud::Hud> >()
//	//m_button = std::make_unique<gui::Button<Hud, void, int> >(*this, &Hud::_Button_OnClick_Event_, 1, "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f));
//	m_button_vec.push_back(std::make_unique<gui::Button<Hud, void, int> >(*this, &Hud::_Button_OnClick_Event_, m_button_vec.size(), "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)));
//	m_button_vec.push_back(std::make_unique<gui::Button<Hud, void, int> >(*this, &Hud::_Button_OnClick_Event_, m_button_vec.size(), "Resources/img/button.png", "Resources/img/button_hoover.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(50.f, 0.f)));
//
//}
//
//
//Hud::~Hud()
//{
//}
//
//
//void Hud::Update(sf::Vector2f windowsize)
//{
//
//}
//
//void Hud::HandleEvents(sf::Event event, sf::Vector2i mousepos)
//{
//	//button->HandleEvents(event, mousepos);
//
//	for (auto& button : m_button_vec)
//	{
//		button->HandleEvents(event, mousepos);
//	}
//}
//
//void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	for (auto& button : m_button_vec)
//	{
//		target.draw(*button);
//	}
//}
//
//template <class C, class Tr, class... Args>
//void Hud::CreateButton(Args& args)
//{
//	Tr(C::*)
//}
//
//void Hud::_Button_OnClick_Event_(int id)
//{
//	
//}