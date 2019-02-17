#include <iostream>                  // might remove later
#include <SFML/Graphics/Font.hpp>  // might remove later
#include <SFML/Graphics/Sprite.hpp>  // might remove later
#include <SFML/Graphics/Texture.hpp> // might remove later
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp> // to get elapsed (or "delta") time
#include <SFML/System/Time.hpp>  // to get elapsed (or "delta") time
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp> // for closing window with ESC

#include "map.h"
#include "player_snake.h"
#include "resource_manager.h"
#include "wall.h"

int main()
{
	// set window size
	// might put into 'game' or 'board' object later
	// to easily set up player coordinates and texture/sprite details
	size_t window_width{800};
	size_t window_height{600};
	char game_program_name[] {"SNAKE"};

	// currently only holds textures, but can store other resource types.
	// like sounds or something.
	Resource_Manager rm;


	// create a player object
	// x/y coordinates, x/y velocity
	Player_Snake ps1(window_width/2, window_height/2);

	// create texture and sprite
	// might add to Player_Snake object
	sf::Texture snek_t;
	snek_t.loadFromFile("assets/textures/snek_t.png");
	sf::Sprite snek_s(snek_t); 

	// move sprite to center of window
	snek_s.setPosition(ps1.get_x_coordinate(), ps1.get_y_coordinate());

	// create a map 25x25 tiles large.
	// pass in window dimensions to check it's in-screen.
	// pass in the resource manager for various reasons.
	Map map(25, 25, window_width, window_height, rm);



	// keep around for reference
	// will add title eventually ... maybe.
	sf::Font main_font;
	main_font.loadFromFile("assets/fonts/LiberationMono-Regular.ttf");



	// used for elapsed (or "delta") time.
	sf::Clock game_clock;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), game_program_name);


	// if too low, snake can easily clip through walls
	// this is because it's able to get so far into the wall
	// it thinks the snake came from a different side.

	// i think a goldilocks number is best. give it a high value
	// to avoid problems mentioned above, but don't let it update
	// as best it possbily can (this kills CPU).
	window.setFramerateLimit(200);


    while (window.isOpen())
    {
		// events go in this while loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}

			// close window with ESC
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
                window.close();
			}
        }
        window.clear();

		// restart() gives us getElapsedTime() and also resets game_clock.
		sf::Time elapsed_time = game_clock.restart();


		// get data from Player_snake.
		// NOTE: might adjust collision to walls only or some combination.
		ps1.get_movement_from_keyboard();
		ps1.check_player_collision(window_width, window_height);
		ps1.update_player_position(snek_s, elapsed_time);


		// run wall collisions.
		// draw the wall sprites.
		for(size_t i {0}; i < map.get_map_walls().size(); ++i)
		{
			map.get_map_walls()[i].check_collision(ps1, snek_s);
			window.draw(map.get_map_walls()[i].get_sprite());
		}

		// draw the snake sprite.
        window.draw(snek_s);

        window.display();
    }

    return 0;
}

