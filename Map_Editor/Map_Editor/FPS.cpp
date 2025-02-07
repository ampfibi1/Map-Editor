#include "FPS.h"

FPS::FPS() : fps("Fps : 0") , max_sec(1.f)
{
}

FPS::~FPS()
{
}

void FPS::Load()
{
	if (font.loadFromFile("Assets/Font/arial.ttf")) {
		printf("Font Load");
		text.setFont(font);
		text.setString(fps);
		mouseText.setFont(font);
		mouseText.setPosition(sf::Vector2f(0, 40));
	}
	else printf("Font not laod ");
}

void FPS::Update(float delta_time , sf::Vector2i mousePos)
{
	if (clock.getElapsedTime().asSeconds() >= max_sec) {
		fps = "Fps : " + std::to_string(int(1 / delta_time));
		text.setString(fps);
		clock.restart();
	}
	mouseP = "X : " + std::to_string(mousePos.x) + 
			 "     Y :" + std::to_string(mousePos.y);
	mouseText.setString(mouseP);
}

void FPS::Draw(sf::RenderWindow& window)
{
	window.draw(text);
	window.draw(mouseText);
}
