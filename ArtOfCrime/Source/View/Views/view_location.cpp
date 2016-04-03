#include "view_location.h"
#include "view_team.h"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>


ViewLocation::ViewLocation(ViewManager& view_manager, NPC& team_member, std::vector<Location>& locations)
{
    m_gui.CreateFrame(TextureData("Resources/Img/Hud/map.png", sf::Vector2f(0.7f, 0.7f)), sf::Vector2f(15, 50));

    m_gui.CreateText("Choose location", 30, sf::Vector2f(300, 5), sf::Color::Black, sf::Text::Bold);

    m_gui.CreateButton<void, ViewManager>("Resources/Img/Hud/button_close.png", "Resources/Img/Hud/button_close.png",
        sf::Vector2f(0.05f, 0.05f), sf::Vector2f(750.f, 40.f), &ViewManager::PopView, view_manager);

    m_gui.CreateButton<void, ViewManager, NPC&, std::vector<Location>&>("Resources/Img/Hud/button_back.png", "Resources/Img/Hud/button_back.png",
        sf::Vector2f(0.3f, 0.3f), sf::Vector2f(350.f, 500.f), &ViewManager::ChangeView<ViewTeam, NPC&, std::vector<Location>&>, view_manager, team_member, locations);
}


ViewLocation::~ViewLocation()
{
}


void ViewLocation::Update(sf::Vector2f windowsize)
{
    m_gui.Update(windowsize);
}

void ViewLocation::HandleEvents(sf::Event event, sf::Vector2i mousepos)
{
    m_gui.HandleEvents(event, mousepos);
}

void ViewLocation::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background_sprite);
    target.draw(m_ally_sprite);
    target.draw(m_header);
    target.draw(m_locations);

    m_gui.Draw(target, states);
}