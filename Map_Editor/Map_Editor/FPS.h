#pragma once
#include<SFML/Graphics.hpp>
#include<string>

class FPS
{
private:
	sf::Text text , mouseText; 
	sf::Font font; 
	std::string fps; 
	sf::Clock clock; 
	const float max_sec;
	std::string mouseP; 
public:
	FPS();
	~FPS();
	void Load(); 
	void Update(float delta_time,sf::Vector2i mousePos); 
	void Draw(sf::RenderWindow& window);
};