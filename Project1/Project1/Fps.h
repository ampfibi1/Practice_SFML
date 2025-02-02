#pragma once
#include<SFML/Graphics.hpp>

class Fps
{
private:
	sf::Text frame_rate;
	sf::Font font;
	sf::Clock fpsClock;
public:
	void Initialize();
	void Update(float delta_time);
	void Draw(sf::RenderWindow& window);
};