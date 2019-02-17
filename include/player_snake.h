#ifndef PLAYER_SNAKE_H
#define PLAYER_SNAKE_H

#include <iostream> // debugging
#include <SFML/Graphics/Sprite.hpp> // handle player sprite
#include <SFML/System/Time.hpp>  // to get elapsed (or "delta") time
#include <SFML/Window/Keyboard.hpp> // move player using keys


class Player_Snake
{
private:
	float m_x_coordinate;
	float m_y_coordinate;
	float m_width;
	float m_height;
	const unsigned char m_moving_up;
	const unsigned char m_moving_right;
	const unsigned char m_moving_down;
	const unsigned char m_moving_left;
	const unsigned char m_moving_up_right;
	const unsigned char m_moving_right_down;
	const unsigned char m_moving_down_left;
	const unsigned char m_moving_left_up;
	unsigned char m_moving; // change as player moves
	float m_default_speed;
	float m_x_velocity;
	float m_y_velocity;
	bool m_player_facing_right;

public:
	// default constructor
	Player_Snake();

	// so we can set sprite in center of screen
	Player_Snake(float x_coordinate, float y_coordinate);

	void get_movement_from_keyboard();

	void check_player_collision(const int &window_width, const int &window_height);

	void update_player_position(sf::Sprite &player_sprite, sf::Time &elapsed_time);

	float get_x_coordinate();
	float get_y_coordinate();
	float get_width() const;
	float get_height() const;
	float get_x_velocity();
	float get_y_velocity();

	void set_x_coordinate(float nxc);
	void set_y_coordinate(float nyc);
	void set_x_velocity(float nxv);
	void set_y_velocity(float nyv);
};

#endif

