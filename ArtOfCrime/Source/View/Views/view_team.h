#pragma once
#include "view.h"
#include "gui.h"
#include "view_manager.h"
#include "npc.h"
#include "location.h"


class ViewTeam : public View
{
public:
	ViewTeam(ViewManager& view_manager, NPC& team_member, std::vector<Location>& locations);
	~ViewTeam();

	void Update(sf::Vector2f windowsize);

	void HandleEvents(sf::Event event, sf::Vector2i mousepos);

	void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	ViewManager& m_view_manager;
	NPC& m_team_member;
	GUI m_gui;


	

};

