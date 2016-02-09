#pragma once
#include "state.h"
#include "item.h"
#include "npc.h"
#include "location.h"

class MissionView : public State
{
public:
	// Get the instance of this state. (Singleton implementation)
	static MissionView& GetInstance()
	{
		static MissionView instance;
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
	MissionView(MissionView const&) = delete;
	void operator=(MissionView const&) = delete;

	// Singleton, hide this.
	MissionView() {};

	// Vector containing all actors
	std::vector<std::unique_ptr<Npc> > m_npcvector;

	// Vector containing all locations
	std::vector<std::shared_ptr<Location> > m_locationvector;

	// Background sprite
	sf::Sprite m_bgsprite;

	// Background texture
	sf::Texture m_bgtexture;

};

