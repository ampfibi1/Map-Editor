#include "mouseTile.h"

mouseTile::mouseTile()
{
}

mouseTile::~mouseTile()
{
}

void mouseTile::Load()
{
	if (mapTexture.loadFromFile("Assets/map/map.png")) {
		printf("Map Load\n");
		mapSprite.setTexture(mapTexture); 
		mapSprite.setTextureRect(sf::IntRect(1*16,0,16,16)); 
		mapSprite.setScale(sf::Vector2f(5, 5));
		mapSprite.setPosition(sf::Vector2f(100, 100));
	}
	else printf("Map does not Load \n");
}

void mouseTile::Update(float delta_time,sf::Vector2i mousePos)
{
	

	int x = (mousePos.x - 100 )/( 16*5); 
	int xx = x * 16 * 5 + 100; 

	int y = (mousePos.y-100) / (16*5); 
	int yy = y * 16 * 5  +  100;

	//mapSprite.setPosition(sf::Vector2f(mousePos));

	mapSprite.setPosition(sf::Vector2f(xx,yy));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		mapSPrites.push_back(mapSprite);
		int i = mapSPrites.size() - 1; 
		sf::Vector2f position = sf::Vector2f(mousePos) / (16.f+100); 
		mapSPrites[i].setPosition(sf::Vector2f(xx,yy));
	}
}

void mouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(mapSprite);
	for (auto x : mapSPrites) window.draw(x);
}
