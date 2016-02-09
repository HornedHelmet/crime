#include "state_manager.h"
#include "state.h"
#include "SFML\Graphics\RenderTarget.hpp"
#include "SFML\Graphics\RenderStates.hpp"

StateManager::StateManager()
{

}

StateManager::StateManager(State* state)
{
    PushState(state);
}


StateManager::~StateManager()
{
}


void StateManager::Update(sf::Vector2f windowsize)
{

    m_states.back()->Update(windowsize);
}

void StateManager::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_states.back());
}

void StateManager::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{

    m_states.back()->HandleEvents(event, mousepos);
}

void StateManager::ChangeState(State* state)
{
    if (!m_states.empty())
    {
        m_states.back()->Clean();
        m_states.pop_back();
    }
    m_states.push_back(state);
    m_states.back()->Initialize();
}

void StateManager::PushState(State* state)
{
    if (!m_states.empty())
    {
        m_states.back()->Pause();
    }
    m_states.push_back(state);
    m_states.back()->Initialize();
}

void StateManager::PopState()
{
    if (m_states.size() > 0)
    {
        m_states.back()->Clean();
        m_states.pop_back();
    }
}

bool StateManager::IsEmpty()
{
	return m_states.size() > 0 ? false : true;
}