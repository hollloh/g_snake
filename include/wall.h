#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics/Sprite.hpp> // handle wall (and snake) sprites
#include <SFML/Graphics/Texture.hpp> // handle wall (and snake) textures
#include "player_snake.h" // adjust snake's position in check_collision()

class Wall
{
private:
	float      m_x_coordinate;
	float      m_y_coordinate;
	float      m_width;
	float      m_height;
	sf::Sprite m_sprite;

public:
	Wall();
	Wall(sf::Texture &wall_texture);

	void check_collision(Player_Snake &ps, sf::Sprite &sprite); // check player is not in wall

	float get_x_coordinate() const;
	float get_y_coordinate() const;
	float get_width() const;
	float get_height() const;
	void set_x_coordinate(float nxc);
	void set_y_coordinate(float nyc);
	sf::Sprite get_sprite();


	// simply calls sf::Sprite's setTexture() function.
	void setTexture(const sf::Texture &texture);

	// simpy calls sf::Sprite's setPosition() function.
	void setPosition(float x, float y);
};

#endif

