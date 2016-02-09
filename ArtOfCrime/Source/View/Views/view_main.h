#pragma once
#include "view.h"
#include "debug.h"

class ViewMain : public View
{
public:
	ViewMain();
	~ViewMain();

	void Update(sf::Vector2f windowsize);

	void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

