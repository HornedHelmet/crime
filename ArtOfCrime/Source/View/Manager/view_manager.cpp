#include "view_manager.h"
#include "view_main.h"


ViewManager::ViewManager()
{

}


ViewManager::~ViewManager()
{
}

void ViewManager::Update(sf::Vector2f windowsize)
{
	if (!m_views.empty())
	{
		m_views.back()->Update(windowsize);
	}
}

void ViewManager::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	if (!m_views.empty())
	{
		m_views.back()->HandleEvents(event, mousepos);
	}
}

void ViewManager::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!m_views.empty())
	{
		m_views.back()->Draw(target, states);
	}
}