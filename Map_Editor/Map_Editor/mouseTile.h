#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class mouseTile
{
private:
	sf::Texture mapTexture; 
	sf::Sprite mapSprite;
	std::vector<sf::Sprite> mapSPrites; 
public:
	mouseTile();
	~mouseTile();
	void Load();
	void Update(float delta_time, sf::Vector2i mousePos);
	void Draw(sf::RenderWindow& window);
};