#pragma once
#include "state.h"
#include "item.h"
#include "npc.h"
#include "location.h"
#include <memory>
#include "interactable.h"

// This class is used when the game is running normally. 
class StateRunning : public State
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
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

private:

	// Singleton, delete these.
	StateRunning(StateRunning const&) = delete;
	void operator=(StateRunning const&) = delete;

    // Singleton, hide this.
    StateRunning(){};


    // Vector containing all items (temporary)
    std::vector<std::unique_ptr<Item> > m_itemvector;

    // Vector containing all actors
    std::vector<std::unique_ptr<Npc> > m_npcvector;

	std::vector<std::shared_ptr<Location> > m_locationvector;
		 
};
 
