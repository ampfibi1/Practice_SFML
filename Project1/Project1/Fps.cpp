#include "Fps.h"
#include<iostream>
using namespace std; 

void Fps::Initialize()
{
	if (font.loadFromFile("Asset/arial.ttf")) {
		frame_rate.setFont(font);
	}
	else
		std::cout << "font not load" << endl;
}

void Fps::Update(float delta_time)
{
	if (fpsClock.getElapsedTime().asSeconds() >= 1.f) {
		std::string frame_rate_text = "FPS : " + to_string(int(1 / delta_time)) +
			"Frame Time : "
			+ to_string(delta_time);
		frame_rate.setString(frame_rate_text);
		fpsClock.restart();
	}
}

void Fps::Draw(sf::RenderWindow& window)
{
	window.draw(frame_rate);
}
