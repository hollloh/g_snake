#include "map.h"

Map::Map(size_t rows, size_t columns, const size_t window_width, const size_t window_height, Resource_Manager &rm):
	m_rows(rows),
	m_columns(columns),
	m_tile_width(20),
	m_tile_height(20)
{

	// check map's in window frame
	assert(m_rows                    > 0            &&
	       m_columns                 > 0            &&
	       m_rows * m_tile_width     < window_width &&
	       m_columns * m_tile_height < window_height);


	// default border map
	// might store somewhere else later.

	m_map_layout += "#########################";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#.......................#";
	m_map_layout += "#########################";

	// nwi = new wall index
	int nwi {0};

	// find how big our vector needs to be.
	for(size_t i {0}; i < m_columns; ++i)
	{
		for(size_t j {i}; j < m_map_layout.length(); j += m_rows)
		{
			if(m_map_layout[j] == '#')
			{
				++nwi;
			}
		}
	}
	// resize vector accordingly.
	m_map_walls.resize(nwi);


	// reset, because we'll use it to keep track of our nameless
	// Wall objects in our vector
	nwi = 0;


	// "teach" a 1-d string to act as a 2-d map of a level.
	for(size_t i {0}; i < m_columns; ++i)
	{
		for(size_t j {i}; j < m_map_layout.length(); j += m_rows)
		{

			// can later add different types of objects to our "map".
			if(m_map_layout[j] == '#')
			{
				// create the object
				// set it's x/y coordinates
				// set it's sprite position
				m_map_walls[nwi] = Wall(rm.get_wall_texture());
				m_map_walls[nwi].set_x_coordinate(i * m_tile_width);

				if(j < m_rows)
				{
					m_map_walls[nwi].set_y_coordinate(0);
				}
				else
				{
					m_map_walls[nwi].set_y_coordinate(((j - i) / m_rows) * m_tile_height);
				}
				m_map_walls[nwi].setPosition(m_map_walls[nwi].get_x_coordinate(), m_map_walls[nwi].get_y_coordinate());

				++nwi;
			}
		}
	}
}


std::vector<Wall> Map::get_map_walls()
{
	return m_map_walls;
}

