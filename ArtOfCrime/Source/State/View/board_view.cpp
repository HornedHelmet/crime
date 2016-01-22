#include "board_view.h"
#include "debug.h"

void BoardView::Initialize()
{
	m_itemvector.push_back(std::make_unique<Item>("map", "a map", "Resources/img/map.gif", 0.3f, 200.f, 200.f, "Resources/img/map.gif", 0.7f));

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