#include "wall.h"

Wall::Wall():
	m_x_coordinate(0.0),
	m_y_coordinate(0.0),
	m_width(20),
	m_height(20)
{}


Wall::Wall(sf::Texture &wall_texture):
	m_x_coordinate(0.0),
	m_y_coordinate(0.0),
	m_width(20),
	m_height(20),
	m_sprite(wall_texture)
{}


void Wall::check_collision(Player_Snake &ps, sf::Sprite &sprite) // check player is not in wall
{
	float snake_x = ps.get_x_coordinate();
	float snake_y = ps.get_y_coordinate();
	float snake_w = ps.get_width();
	float snake_h = ps.get_height();

	// initial check for collision in general.
	// all must be true but don't tell us the
	// specifics of where the collision occurs
	if(snake_x + snake_w         >= m_x_coordinate  &&
	   m_x_coordinate + m_width  >= snake_x         &&
	   m_y_coordinate + m_height >= snake_y         &&
	   snake_y + snake_h         >= m_y_coordinate)
	{
 		// start to find the overlapping rectangle
		// between the two sprites
		float dif_l = (snake_x + snake_w)         - m_x_coordinate;
		float dif_r = (m_x_coordinate + m_width)  - snake_x;
		float dif_d = (m_y_coordinate + m_height) - snake_y;
		float dif_u = (snake_y + snake_h)         - m_y_coordinate;

		// determine which of the points are actually colliding.

		// of the two edges, which is the smallest?
		// move the snake out of the wall that is the
		// shortest distance. 

		if(dif_u < dif_r &&
		   dif_u < dif_d &&
		   dif_u < dif_l)
		{
			ps.set_y_coordinate(m_y_coordinate - snake_h);  // pop snake out the top of the wall
		}

		if(dif_r < dif_u &&
		   dif_r < dif_d &&
		   dif_r < dif_l)
		{
				ps.set_x_coordinate(m_x_coordinate + m_width);  // pop snake out to the right of the wall
		}

		if(dif_d < dif_u &&
		   dif_d < dif_r &&
		   dif_d < dif_l)
		{
			ps.set_y_coordinate(m_y_coordinate + m_height); // pop snake out the bottom of the wall
		}

		if(dif_l < dif_u &&
		   dif_l < dif_r &&
		   dif_l < dif_d)
		{
				ps.set_x_coordinate(m_x_coordinate - snake_w);  // pop snake out to the left of the wall
		}
	}
	// visually adjust snake sprite
	sprite.setPosition(snake_x, snake_y);
}


float Wall::get_x_coordinate() const {return m_x_coordinate;}
float Wall::get_y_coordinate() const {return m_y_coordinate;}
float Wall::get_width() const {return m_width;}
float Wall::get_height() const {return m_height;}
void  Wall::set_x_coordinate(float nxc) {m_x_coordinate = nxc;}
void  Wall::set_y_coordinate(float nyc) {m_y_coordinate = nyc;}

sf::Sprite Wall::get_sprite() {return m_sprite;}


void Wall::setTexture(const sf::Texture &texture)
{
	m_sprite.setTexture(texture);
}


void Wall::setPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}


