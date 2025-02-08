#include "Map.h"

Map::Map() : mapSprites(nullptr)
{
}

Map::~Map()
{
	delete[] mapSprites;
}

void Map::Load()
{
	mapSprites = new sf::Sprite[MAP_SIZE]; 
}

void Map::Update(float delta_time)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < MAP_SIZE; i++) window.draw(mapSprites[i]);
}
