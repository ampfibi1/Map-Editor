#pragma once
#include<SFML/Graphics.hpp>
#define MAP_SIZE 50 

class Map
{
private:
	sf::Sprite* mapSprites; 
public:
	Map();
	~Map();
	void Load();
	void Update(float delta_time);
	void Draw(sf::RenderWindow& window);
};

