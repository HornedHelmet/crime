#pragma once
#include "view.h"
#include "npc.h"
#include "view_manager.h"
#include "location.h"
#include "gui.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>
#include <vector>
class ViewLocation : public View
{
public:
	ViewLocation(ViewManager& view_manager, NPC& team_member, std::vector<Location>& locations);
	~ViewLocation();

    void Update(sf::Vector2f windowsize);

    void HandleEvents(sf::Event event, sf::Vector2i mousepos);

    void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    GUI m_gui;

    sf::Sprite m_background_sprite;
    sf::Texture m_background_texture;
    sf::Sprite m_ally_sprite;
    sf::Texture m_ally_texture;
    sf::Font m_font;
    sf::Text m_header;
    sf::Text m_locations;
};

