#pragma once

namespace sf
{
    class RenderTarget;
    class Event;
}

// Base class for all game states. 
// All children should be singletons.
class State
{

public: 
    // Initialize state.
    virtual void Initialize() = 0;

    // Clean state.
    virtual void Clean() = 0;

    // Pause state.
    virtual void Pause() = 0;

    // Update state.
    virtual void Update(float time) = 0;

    // Draw state.
    virtual void Draw(sf::RenderTarget& target) = 0;

    // Handle events for this state.
    virtual void HandleEvents(sf::Event event) = 0;
};