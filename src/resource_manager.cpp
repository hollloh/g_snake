#include "resource_manager.h"

Resource_Manager::Resource_Manager()
{
	m_wall_texture.loadFromFile("assets/textures/wall.png");
}


sf::Texture& Resource_Manager::get_wall_texture()
{
	return m_wall_texture;
}

