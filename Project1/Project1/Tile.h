#pragma once
#include<SFML/Graphics.hpp>

struct Tile {
	int id = -1; 

	sf::Texture* texture = nullptr;
	sf::Vector2i position; 
};