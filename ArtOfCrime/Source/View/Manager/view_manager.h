#pragma once
#include "runnable_drawable.h"
#include "view.h"
#include "object.h"
#include "npc.h"
#include <vector>
#include <memory>

class ViewManager : public aoc::RunnableDrawable
{
public:
	ViewManager();
	~ViewManager();

	void Update(sf::Vector2f windowsize);

	void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

	template<class view>
	void ChangeView()
	{
		if (std::is_base_of<View, view>())
		{
			if (!m_views.empty())
			{
				m_views.pop_back();
			}
			m_views.push_back(std::make_unique<view>());
		}
	}

	template<class view>
	void PushView()
	{
		if (std::is_base_of<View, view>())
		{
			m_views.push_back(std::make_unique<view>());
		}
	}

	template<class view>
	void PushView(AObject& a_object)
	{
		if (std::is_base_of<View, view>())
		{
			m_views.push_back(std::make_unique<view>(*this, a_object));
		}
	}

	void PopView()
	{
		if (!m_views.empty())
		{
			m_views.pop_back();
		}
	}


private:
	
	std::vector<std::unique_ptr<View> > m_views;
};

