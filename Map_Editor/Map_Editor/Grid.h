#pragma once
#include<SFML/Graphics.hpp>

class Grid
{
private:
	std::vector<sf::RectangleShape> h , v; 
	sf::Vector2i cellSize;
	sf::Vector2i totalCells;
	sf::Vector2i totalLine; 
	int LineThickness;
	sf::Vector2f position; 

	const int scale; 
public:
	Grid(const sf::Vector2i & totalCells);
	~Grid();
	void Load();
	void Update(float delta_time);
	void Draw(sf::RenderWindow& window);
};
