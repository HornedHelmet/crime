#pragma once
#include "state.h"
#include "state_manager.h"
#include "change_state_button.h"
#include <memory>


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

private:

	// Singleton, delete these.
	StateRunning(StateRunning const&) = delete;
	void operator=(StateRunning const&) = delete;

    // Singleton, hide this.
    StateRunning(){};

	std::shared_ptr<StateManager> m_sm_view;

	std::vector<std::unique_ptr<gui::ChangeStateButton> > m_view_buttons;

		 
};
 
