//#include "button.h"
//#include "mouse.h"
//
//
//Button::Button(std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position)
//{
//	if (m_texture.loadFromFile(default_texture) && m_texture_hoover.loadFromFile(hoover_texture))
//	{
//		m_sprite.setTexture(m_texture);
//		m_sprite.setScale(scale);
//	}
//
//	m_sprite.setPosition(position);
//}
//
//
//Button::~Button()
//{
//}
//
//void Button::HandleEvents(sf::Event event, sf::Vector2i mousepos)
//{
//	if (Mouse::IsMouseOver(m_sprite, mousepos))
//	{
//		if (!b_hoovered)
//		{
//			HooverBegin();
//		}
//
//		if ((!b_clicked || b_allow_repeat_click) && Mouse::IsMouseButtonPressed(event, sf::Mouse::Left))
//		{
//			OnClick();
//		}
//	}
//	else
//	{
//		if (b_hoovered)
//		{
//			HooverEnd();
//		}
//		if (b_clicked && Mouse::IsMouseButtonPressed(event, sf::Mouse::Left))
//		{
//			UnClick();
//		}
//	}
//}
//
//void Button::HooverBegin()
//{
//	b_hoovered = true;
//	//Mouse::SetIsHooveringClickable(this, true);
//	m_sprite.setTexture(m_texture_hoover);
//}
//
//
//void Button::HooverEnd()
//{
//	b_hoovered = false;
//	//Mouse::SetIsHooveringClickable(this, false);
//	m_sprite.setTexture(m_texture);
//}
//
//
//void Button::OnClick()
//{
//	b_clicked = true;
//}
//
//void Button::UnClick()
//{
//	b_clicked = false;
//}