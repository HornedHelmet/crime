#pragma once
#include "button.h"
#include "state_manager.h"
#include <memory>

namespace gui 
{
	class ChangeStateButton :
		public Button
	{
	public:
		ChangeStateButton(std::string debugname, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position, std::shared_ptr<StateManager> const& state_manager, State* state);
		~ChangeStateButton();
		

	protected:
		virtual void OnClick();
		virtual void UnClick();

	private:
		std::shared_ptr<StateManager> const& m_state_manager;
		State* m_state;
		std::string name;
	};
}


