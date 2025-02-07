#include "Grid.h"

Grid::Grid(const sf::Vector2i& totalCells) : totalCells(totalCells)
			, cellSize(16,16), LineThickness(2), position(sf::Vector2f(100, 100))
			, scale(5)
{
	totalLine = totalCells + sf::Vector2i(1,1);
}

Grid::~Grid()
{
}

void Grid::Load()
{
	int horizontalLineLength = totalCells.x * cellSize.x * scale; 
	int verticalLineLength = totalCells.y * cellSize.y * scale; 

	for (int i = 0; i < totalLine.y; ++i) {
		sf::RectangleShape l; 
		l.setSize(sf::Vector2f(horizontalLineLength, LineThickness));
		l.setPosition(position+sf::Vector2f(0,i*cellSize.x*scale));
		h.push_back(l);
	}
	for (int i = 0; i < totalLine.x; ++i) {
		sf::RectangleShape l; 
		l.setSize(sf::Vector2f(verticalLineLength, LineThickness));
		l.setPosition(position + sf::Vector2f(i * cellSize.y * scale, 0));
		l.setRotation(90);
		v.push_back(l);
	}
}

void Grid::Update(float delta_time)
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	for(auto x:h)window.draw(x); 
	for(auto x:v)window.draw(x);
}