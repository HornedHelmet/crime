#pragma once
#include "runnable_drawable.h"
#include <vector>

class State;

// Manager of all game states.
class StateManager : public aoc::RunnableDrawable
{
public:
	StateManager();
    StateManager(State* state);
    ~StateManager();

    // Update state at the back of the state stack.
    virtual void Update(sf::Vector2f windowsize);

	// Draw state at the back of the state stack.
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Handle events for the state at the back of the state stack.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

    // Replace the current state with a new state.
    void ChangeState(State* state);
    
    // Push a new state to the back of the state stack.
    // Current state is paused.
    void PushState(State* state);
    
    // Remove the state at the back of the state stack.
    void PopState();

	bool IsEmpty();

private:

    // State stack container.
    std::vector<State*> m_states;
};

