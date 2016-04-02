#include "view_location.h"
#include "view_team.h"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>


ViewLocation::ViewLocation(ViewManager& view_manager, NPC& team_member, std::vector<Location>& locations)
{
    if (m_ally_texture.loadFromFile("Resources/Img/Hud/ally_frame.png"))
    {
        m_ally_sprite.setTexture(m_ally_texture);
        m_ally_sprite.setScale(0.8f, 0.8f);
        m_ally_sprite.setPosition(250, 50);
    }

    if (m_background_texture.loadFromFile("Resources/Img/Hud/grey_bg.png"))
    {
        m_background_sprite.setTexture(m_background_texture);
        m_background_sprite.setColor(sf::Color(255, 255, 255, 125));
    }

    if (m_font.loadFromFile("Resources/Font/arial.ttf"))
    {
        m_header.setFont(m_font);
        m_header.setCharacterSize(30);
        m_header.setStyle(sf::Text::Bold);
        m_header.setPosition(300, 100);
        m_header.setColor(sf::Color::Black);
        m_header.setString("Choose location:");

        m_locations.setPosition(300, 150);
        m_locations.setFont(m_font);
        m_locations.setCharacterSize(16);

        std::string temp = "";
        for (auto& location : locations)
        {
            temp += location.GetName() + "\n";
        }
        m_locations.setString(temp);
    }

    m_gui.CreateButton<void, ViewManager>("Resources/Img/Hud/button_close.png", "Resources/Img/Hud/button_close.png",
        sf::Vector2f(0.05f, 0.05f), sf::Vector2f(550.f, 40.f), &ViewManager::PopView, view_manager);

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