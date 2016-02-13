#include "state_manager.h"
#include "state_running.h"
#include "mouse.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


// Load cursor textures and setup sprite.
void LoadCustomCursor(sf::Sprite& sprite, sf::Texture& default_texture, sf::Texture& hoover_texture);

// Update cursor position and swap between textures.
void UpdateCursor(sf::Sprite& sprite, sf::Texture const& default_texture, sf::Texture const& hoover_texture, sf::Vector2i mousepos, bool hoover);


int main()
{

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Art Of Crime - Development");

    // initiate the state manager with the first game state
    StateManager state_manager(&StateRunning::GetInstance());

	// hide default cursor
	window.setMouseCursorVisible(false);

	// setup custom cursor
	sf::Texture default_cursor_texture;
	sf::Texture hoover_cursor_texture;
	sf::Sprite cursor_sprite;
	LoadCustomCursor(cursor_sprite, default_cursor_texture, hoover_cursor_texture);

    // run this loop as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else
            {
	            // handle state events
	            state_manager.HandleEvents(event, sf::Mouse::getPosition(window));
            }
        }
		

        // clear the window with x color
        window.clear(sf::Color::White);

        // update state
		state_manager.Update(window.getView().getSize());

		// draw state
		window.draw(state_manager);

		// Update cursor position and texture
		UpdateCursor(cursor_sprite, default_cursor_texture, hoover_cursor_texture, sf::Mouse::getPosition(window), Mouse::b_hoovering_clickable);

		// draw the cursor
		window.draw(cursor_sprite);

        // end the current frame
        window.display();
    }

    return EXIT_SUCCESS;
}

void UpdateCursor(sf::Sprite& sprite, sf::Texture const& default_texture, sf::Texture const& hoover_texture, sf::Vector2i mousepos, bool hoover)
{
	hoover ? sprite.setTexture(hoover_texture) : sprite.setTexture(default_texture);
	sprite.setPosition(static_cast<sf::Vector2f>(mousepos));
	Mouse::b_hoovering_clickable = false;
}

void LoadCustomCursor(sf::Sprite& sprite, sf::Texture& default_texture, sf::Texture& hoover_texture)
{
	if (default_texture.loadFromFile("Resources/Img/Cursor/default_cursor.png") &&
		hoover_texture.loadFromFile("Resources/Img/Cursor/hoover_cursor.png"))
	{
		sprite.setTexture(default_texture);
		sprite.setScale(0.05f, 0.05f);
	}
}