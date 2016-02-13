#pragma once
#include "runnable_drawable.h"

class View : public aoc::RunnableDrawable
{

public:
	virtual void Update(sf::Vector2f windowsize) = 0;

	virtual void HandleEvents(sf::Event event, sf::Vector2i mousepos) = 0;

	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};