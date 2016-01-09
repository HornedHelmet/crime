#include "state_manager.h"
#include "state_running.h"
#include "algorithm_aoc.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "debug.h"
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Art Of Crime - Development");

    // initiate the state manager with the first game state
    StateManager sm(&StateRunning::GetInstance());

    // start game timer
    sf::Clock clock;

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
                sm.HandleEvents(event, sf::Mouse::getPosition(window));
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // update and draw everything here...
        sm.Update(clock.getElapsedTime().asSeconds());
        sm.Draw(window);

        // end the current frame
        window.display();
    }

    return 0;
}

