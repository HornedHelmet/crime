#pragma once
#include "state.h"
#include "item.h"
#include <memory>

class StateRunning :
    public State
{
public:
    // Get the instance of this state. (Singleton implementation)
    static StateRunning& GetInstance()
    {
        static StateRunning instance;
        return instance;
    }

    // Initialize this state.
    virtual void Initialize();
    
    // Clean this state.
    virtual void Clean();

    // Pause this state.
    virtual void Pause();

    // Update this state.
    virtual void Update(float time);

    // Draw this state.
    virtual void Draw(sf::RenderTarget& targets);

    // Handle events for this state.
    virtual void HandleEvents(sf::Event event);

private:
    // Singleton, hide this.
    StateRunning(){};

    // Singleton, delete these.
    StateRunning(StateRunning const&) = delete;
    void operator=(StateRunning const&) = delete;

    // Vector containing all items (temporary)
    std::vector<std::unique_ptr<Item> > m_itemvector;

};
 
