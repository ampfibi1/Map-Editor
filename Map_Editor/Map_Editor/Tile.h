#pragma once
#include<SFML/Graphics.hpp>

struct Tile {
	int id = -1;
	sf::Vector2f position; 
	sf::Texture* texture = nullptr; 
};