#pragma once
#include "state.h"
#include <vector>

// Manager of all game states.
class StateManager 
{
public:
    StateManager(State* state);

    ~StateManager();

    // Update state at the back of the state stack.
    virtual void Update(float time);

    // Draw state at the back of the state stack.
    virtual void Draw(sf::RenderTarget& target);

    // Handle events for the state at the back of the state stack.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

    // Replace the current state with a new state.
    void ChangeState(State* state);
    
    // Push a new state to the back of the state stack.
    // Current state is paused.
    void PushState(State* state);
    
    // Remove the state at the back of the state stack.
    void PopState();

private:
    StateManager() {};

    // State stack container.
    std::vector<State*> m_states;
};

