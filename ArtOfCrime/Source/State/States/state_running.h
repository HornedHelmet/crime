#pragma once
#include "state.h"
#include "hud.h"
#include "npc.h"
#include "view_manager.h"
#include "view_main.h"

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
    virtual void Update(sf::Vector2f windowsize);

	// Specify how the class should be drawn (inherited from Drawable).
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Handle events for this state.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);


private:

	// Singleton, delete these.
	StateRunning(StateRunning const&) = delete;
	void operator=(StateRunning const&) = delete;

    // Singleton, hide this.
	StateRunning();

	HUD m_hud;
	ViewManager m_view_manager;

	NPC m_npc1;
	NPC m_npc2;
	//std::vector<NPC> m_npc_vector;
	//NPC npc1, npc2, npc3;
		 
};
 
