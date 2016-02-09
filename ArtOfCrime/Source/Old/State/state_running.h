#pragma once
#include "state.h"
#include "state_manager.h"
#include "hud.h"
#include "npc.h"
#include "location.h"
#include <memory>
#include "debug.h"

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
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Handle events for this state.
    virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	void _Interactable_Clicked_(Actor& actor)
	{
		//Debug::Print(actor.GetName());
	}

private:

	// Singleton, delete these.
	StateRunning(StateRunning const&) = delete;
	void operator=(StateRunning const&) = delete;

    // Singleton, hide this.
	StateRunning();

	//std::shared_ptr<StateManager> m_sm_view;

	//std::vector<std::unique_ptr<gui::ChangeStateButton> > m_view_buttons;

	//std::shared_ptr<StateManager> m_sm_popup;
	//std::vector<std::unique_ptr<gui::ChangeStateButton> > m_popup_buttons;


	//// Vector containing all actors
	std::vector<std::unique_ptr<Npc> > m_npcvector;

	// Vector containing all locations
	std::vector<std::shared_ptr<Location> > m_locationvector;

	std::unique_ptr<Hud<State, void, Actor&>> m_hud;

		 
};
 
