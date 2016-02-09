#pragma once
#include "state.h"
#include "item.h"
#include "npc.h"
#include "location.h"

class BoardView : public State
{
public:
	// Get the instance of this state. (Singleton implementation)
	static BoardView& GetInstance()
	{
		static BoardView instance;
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
	BoardView(BoardView const&) = delete;
	void operator=(BoardView const&) = delete;

	// Singleton, hide this.
	BoardView() {};


	// Vector containing all items (temporary)
	std::vector<std::unique_ptr<Item> > m_itemvector;

	// Background sprite
	sf::Sprite m_bgsprite;

	// Background texture
	sf::Texture m_bgtexture;
};

