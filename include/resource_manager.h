#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics/Texture.hpp> // handle wall textures (and future things)

class Resource_Manager
{
private:
	sf::Texture m_wall_texture;

public:
	Resource_Manager();

	sf::Texture& get_wall_texture();
};

#endif

