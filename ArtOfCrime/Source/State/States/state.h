#pragma once
#include "runnable.h"
#include "drawable.h"

// Base class for all game states. 
// All children should be singletons.
class State : public aoc::Runnable, public aoc::Drawable
{

public: 
    // Initialize state.
    virtual void Initialize() = 0;

    // Clean state.
    virtual void Clean() = 0;

    // Pause state.
    virtual void Pause() = 0;

    // Update state.
    virtual void Update(sf::Vector2f windowsize) = 0;

	// Specify how the class should be drawn (inherited from Drawable).
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    // Handle events for this state.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos) = 0;

};