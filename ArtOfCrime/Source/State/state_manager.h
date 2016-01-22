#pragma once
#include "runnable.h"
#include "state.h"
#include <SFML\Graphics\Drawable.hpp>
#include <vector>

// Manager of all game states.
class StateManager : public Runnable, public sf::Drawable
{
public:
    StateManager(State* state);
    ~StateManager();

    // Update state at the back of the state stack.
    virtual void Update(sf::Vector2f windowsize);

	// Draw state at the back of the state stack.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

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

