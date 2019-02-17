#include "player_snake.h"

Player_Snake::Player_Snake():
	m_x_coordinate(0.0),
	m_y_coordinate(0.0),
	m_width(10),
	m_height(10),
	m_moving_up         (0x1),
	m_moving_right      (0x2),
	m_moving_down       (0x4),
	m_moving_left       (0x8),
	m_moving_up_right   (0x10),
	m_moving_right_down (0x20),
	m_moving_down_left  (0x40),
	m_moving_left_up    (0x80),
	m_moving(0),
	m_default_speed(0.2),
	m_x_velocity(0.0),
	m_y_velocity(0.0),
	m_player_facing_right(true)
{}


// so we can set sprite in center of screen
Player_Snake::Player_Snake(float x_coordinate, float y_coordinate):
	m_x_coordinate(x_coordinate),
	m_y_coordinate(y_coordinate),
	m_width(10),
	m_height(10),
	m_moving_up         (0x1),
	m_moving_right      (0x2),
	m_moving_down       (0x4),
	m_moving_left       (0x8),
	m_moving_up_right   (0x10),
	m_moving_right_down (0x20),
	m_moving_down_left  (0x40),
	m_moving_left_up    (0x80),
	m_moving(0),
	m_default_speed(0.2),
	m_x_velocity(0.0),
	m_y_velocity(0.0),
	m_player_facing_right(true)
{}


void Player_Snake::get_movement_from_keyboard()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_moving |= m_moving_up;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_moving |= m_moving_right;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_moving |= m_moving_down;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_moving |= m_moving_left;

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_moving &= ~m_moving_up;

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_moving &= ~m_moving_right;

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_moving &= ~m_moving_down;

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_moving &= ~m_moving_left;
}


void Player_Snake::check_player_collision(const int &window_width, const int &window_height)
{
	if(m_x_coordinate <= 0.0)
		{m_x_coordinate = 0.0;}

	if((m_x_coordinate + m_width) >= window_width)
		{m_x_coordinate = window_width - m_width;}

	if(m_y_coordinate <= 0.0)
		{m_y_coordinate = 0.0;}

	if((m_y_coordinate + m_height) >= window_height)
		{m_y_coordinate = window_height - m_height;}
}


void Player_Snake::update_player_position(sf::Sprite &player_sprite, sf::Time &elapsed_time)
{
	if(m_moving & m_moving_up)
		{m_y_velocity = m_default_speed * -1;}

	if(m_moving & m_moving_right)
		{m_player_facing_right = true;
		m_x_velocity =  m_default_speed;}

	if(m_moving & m_moving_down)
		{m_y_velocity = m_default_speed;}

	if(m_moving & m_moving_left)
		{m_player_facing_right = false;
		m_x_velocity = m_default_speed * -1;}

	if(!(m_moving & (m_moving_right | m_moving_left)))
		{m_x_velocity = 0.0;}

	if(!(m_moving & (m_moving_up | m_moving_down)))
		{m_y_velocity = 0.0;}

	// get speed by multiplying velocity with time.
	// asMilliseconds() returns an Int32, so that's why the cast is there.
	// asSeconds() returns a float, but i prefer working with milliseconds.
	// if you change asMilliseconds() to asSeconds adjust m_default_speed to some appropriate amount.
	m_x_coordinate += m_x_velocity * static_cast<float>(elapsed_time.asMilliseconds());
	m_y_coordinate += m_y_velocity * static_cast<float>(elapsed_time.asMilliseconds());


	// update snake sprite position.
	player_sprite.setPosition(m_x_coordinate, m_y_coordinate);


	// debug info
	std::cout << m_x_coordinate << '\t' << m_y_coordinate << '\n';
}


float Player_Snake::get_x_coordinate() {return m_x_coordinate;}
float Player_Snake::get_y_coordinate() {return m_y_coordinate;}
float Player_Snake::get_x_velocity() {return m_x_velocity;}
float Player_Snake::get_y_velocity() {return m_y_velocity;}
float Player_Snake::get_width() const {return m_width;}
float Player_Snake::get_height() const {return m_height;}

void Player_Snake::set_x_coordinate(float nxc) {m_x_coordinate = nxc;}
void Player_Snake::set_y_coordinate(float nyc) {m_y_coordinate = nyc;}
void Player_Snake::set_x_velocity(float nxv) {m_x_velocity = nxv;}
void Player_Snake::set_y_velocity(float nyv) {m_y_velocity = nyv;}

