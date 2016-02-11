#pragma once
#include "runnable_drawable.h"
#include "view_main.h"
#include "view.h"
#include <vector>
#include <memory>

// Check if the view is marked for deletion.
extern bool IsMarkedForDeletion(std::pair<std::unique_ptr<View>, bool> const& view);

// The view manager is responsible to contain and change all views or windows that are rendered in the game.
// Everything from gui elements, like buttons, to the main game is rendered through a view. 
class ViewManager : public aoc::RunnableDrawable
{
public:
	ViewManager()
	{
		// Permanent view at the front of the stack.
		m_views.push_back(std::make_pair<>(std::make_unique<ViewMain>(), false));
	};

	~ViewManager() {};

	// Update the current view and erease all marked for deletion.
	void Update(sf::Vector2f windowsize)
	{
		m_views.erase(std::remove_if(m_views.begin(), m_views.end(), IsMarkedForDeletion), m_views.end());

		if (!m_views.empty())
		{
			m_views.back().first->Update(windowsize);
		}
	}

	// Tell views to handle event.
	void HandleEvents(sf::Event event, sf::Vector2i mousepos)
	{
		if (!m_views.empty())
		{
			m_views.back().first->HandleEvents(event, mousepos);
		}
	}

	// Tell views to render.
	void Draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (!m_views.empty())
		{
			m_views.back().first->Draw(target, states);
		}
	}

	// Change the current view for a new one, except if we are down to our bottom view.
	// We then keep that view and just push the new one to the stack.
	template<class NewView, class... Params>
	void ChangeView(Params&... params)
	{
		if (std::is_base_of<View, NewView>())
		{
			if (m_views.size() > 1)
			{
				m_views.back().second = true;
			}
			m_views.push_back(std::make_pair<>(std::make_unique<NewView>(*this, params...), false));
		}
	}

	// Push a new view to the stack.
	template<class NewView, class... Params>
	void PushView(Params&... params)
	{
		if (std::is_base_of<View, NewView>())
		{
			m_views.push_back(std::make_pair<>(std::make_unique<NewView>(*this, params...), false));
		}
	}

	// Remove the view at the top of the stack.
	void PopView()
	{
		if (m_views.size() > 1)
		{
			m_views.back().second = true;
		}
	}


private:
	// A vector containing a pair of views and their life status. (true = marked for deletion)
	std::vector<std::pair<std::unique_ptr<View>, bool> > m_views;


};

