#ifndef MAP_H
#define MAP_H

#include <cassert> // debug checking; make sure walls are in window frame
#include <string>
#include <vector>
#include "resource_manager.h" // get textures for walls (and future resources)
#include "wall.h" // used heavily

class Map
{
private:
	std::string m_map_layout;
	std::vector<Wall> m_map_walls;
	size_t m_rows;
	size_t m_columns;
	size_t m_tile_width;
	size_t m_tile_height;

public:
	Map(size_t rows, size_t columns, const size_t window_width, const size_t window_height, Resource_Manager &rm);

	std::vector<Wall> get_map_walls();
};

#endif

