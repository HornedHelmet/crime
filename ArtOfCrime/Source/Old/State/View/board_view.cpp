#include "board_view.h"
#include "debug.h"

void BoardView::Initialize()
{
	m_itemvector.push_back(std::make_unique<Item>("Name", "Description", "Resources/img/map.gif", "Resources/img/map_hoover.gif", sf::Vector2f(0.3f, 0.3f), sf::Vector2f(200.f, 200.f), "Resources/img/map.gif", sf::Vector2f(0.7f, 0.7f)));

	if (m_bgtexture.loadFromFile("Resources/img/background.jpg"))
	{
		m_bgsprite.setTexture(m_bgtexture);
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load m_bgtexture", "state_running.cpp", "Initialize");
	}
}


void BoardView::Clean()
{
	for (auto& item : m_itemvector)
	{
		item->Clean();
	}
}


void BoardView::Pause()
{

}


void BoardView::Update(sf::Vector2f windowsize)
{
	// Scale background to window size
	m_bgsprite.setScale(windowsize.x / m_bgsprite.getLocalBounds().width, windowsize.y / m_bgsprite.getLocalBounds().height);

	for (auto& item : m_itemvector)
	{
		item->Update(windowsize);
	}

}


void BoardView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_bgsprite);

	for (auto& item : m_itemvector)
	{
		target.draw(*item.get());
	}
}


void BoardView::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
	for (auto& item : m_itemvector)
	{
		item->HandleEvents(event, mousepos);
	}
}