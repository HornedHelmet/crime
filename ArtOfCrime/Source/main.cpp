#include "state_manager.h"
#include "state_running.h"
#include "mouse.h"
#include "debug.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


void LoadCustomCursor(sf::Sprite& sprite, sf::Texture& default_texture, sf::Texture& hoover_texture);
void UpdateCursor(sf::Sprite& sprite, sf::Texture const& default_texture, sf::Texture const& hoover_texture, sf::Vector2i mousepos, bool hoover);


int main()
{
	//ViewManager vm;
	//vm.PushView<ViewMain>();


    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Art Of Crime - Development");

	// hide default cursor
	window.setMouseCursorVisible(false);

    // initiate the state manager with the first game state
    StateManager state_manager(&StateRunning::GetInstance());

	sf::Texture default_cursor_texture;
	sf::Texture hoover_cursor_texture;
	sf::Sprite cursor_sprite;

	LoadCustomCursor(cursor_sprite, default_cursor_texture, hoover_cursor_texture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else
				state_manager.HandleEvents(event, sf::Mouse::getPosition(window));
        }
		

        // clear the window with black color
        window.clear(sf::Color::White);

        // update and draw everything here...
		state_manager.Update(window.getView().getSize());

		// draw the state manager
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
	if (hoover)
	{
		sprite.setTexture(hoover_texture);
	}
	else
	{
		sprite.setTexture(default_texture);
	}

	sprite.setPosition(static_cast<sf::Vector2f>(mousepos));
	Mouse::b_hoovering_clickable = false;
}

void LoadCustomCursor(sf::Sprite& sprite, sf::Texture& default_texture, sf::Texture& hoover_texture)
{
	if (default_texture.loadFromFile("Resources/Img/Cursor/default_cursor.png"))
	{
		sprite.setTexture(default_texture);
		sprite.setScale(0.05f, 0.05f);
	}
	else
	{
		Debug::Print(Debug::warning, "Failed to load default cursor texture", "main", "LoadCustomCursor");
	}

	if (!hoover_texture.loadFromFile("Resources/Img/Cursor/hoover_cursor.png"))
	{
		Debug::Print(Debug::warning, "Failed to load hoover cursor texture", "main", "LoadCustomCursor");
	}
}