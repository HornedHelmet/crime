#pragma once
#include "view.h"
#include "gui.h"
#include "view_manager.h"
#include "npc.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>
#include <memory>

class NPC;
class AObject;


class ViewTeam : public View
{
public:
	ViewTeam(ViewManager& view_manager, NPC& team_member);
	~ViewTeam();

	void Update(sf::Vector2f windowsize);

	void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	ViewManager& m_view_manager;
	NPC m_team_member;
	GUI m_gui;

	sf::Sprite m_background_sprite;
	sf::Texture m_background_texture;
	sf::Sprite m_ally_sprite;
	sf::Texture m_ally_texture;
	sf::Font m_font;
	sf::Text m_name;

	

};

