#include "state_manager.h"
#include "state.h"
#include <SFML\Graphics.hpp>

StateManager::StateManager(State* state)
{
    PushState(state);
}


StateManager::~StateManager()
{
}


void StateManager::Update( float time)
{
    m_states.back()->Update(time);
}

void StateManager::Draw(sf::RenderTarget& target)
{
    m_states.back()->Draw(target);
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
    if (m_states.size() > 1)
    {
        m_states.back()->Clean();
        m_states.pop_back();
    }
}
