#include<SFML/Graphics.hpp>
#include"FPS.h"
#include"Grid.h"
#include"mouseTile.h"

int main() {
	//----------------------------Initialization--------------------------
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Map-Loader");
	window.setFramerateLimit(60);
	FPS fps;
	sf::Clock clock; 
	sf::Time timer; 
	float delta_time; 
	Grid grid(sf::Vector2i(10,5)); 
	mouseTile mousetile; 
	sf::Vector2i mousePos; 
	//----------------------------Initialization--------------------------
	//----------------------------Load--------------------------
	fps.Load();
	grid.Load();
	mousetile.Load();
	//----------------------------Load--------------------------
	while (window.isOpen()) {
		timer = clock.restart();
		delta_time = timer.asSeconds();
		//----------------------------Update--------------------------
		sf::Event event;
		while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		mousePos = sf::Vector2i(sf::Mouse::getPosition(window));
		fps.Update(delta_time,mousePos);
		grid.Update(delta_time);
		mousetile.Update(delta_time,mousePos);
		//----------------------------Update--------------------------
		//----------------------------Draw--------------------------
		window.clear(sf::Color::Black); 
		mousetile.Draw(window);
		grid.Draw(window); 
		fps.Draw(window);
		window.display();
		//----------------------------Draw--------------------------
	}
}