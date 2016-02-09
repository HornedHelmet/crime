#include "change_state_button.h"
#include "debug.h"
using namespace gui;


ChangeStateButton::ChangeStateButton(std::string debugname, std::string default_texture, std::string hoover_texture, sf::Vector2f scale, sf::Vector2f position, std::shared_ptr<StateManager> const& state_manager, State* state)
	: Button(default_texture, hoover_texture, scale, position),
	m_state(state),
	m_state_manager(state_manager)
{
	name = debugname;

}

ChangeStateButton::~ChangeStateButton()
{
}

void ChangeStateButton::OnClick()
{
	//Debug::Print(name + " Click");
	m_state_manager->ChangeState(m_state);
}

void ChangeStateButton::UnClick()
{
	//Debug::Print(name + " UnClick");
}
