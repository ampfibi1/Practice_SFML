#include<SFML/Graphics.hpp>
#include<iostream>
#include"Bullet.h"
#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include"Math.h"
#include"Fps.h"
using namespace std; 

int main() {
	//------------------------initialize---------------------------------
	sf::RenderWindow window(sf::VideoMode(1080, 700), "Tester");
	window.setFramerateLimit(60);

	Player player; 
	Map map;
	Enemy enemy;
	Fps fps; 

	sf::Clock clock;
	sf::Time deltaTimer;

	player.Initialize();
	enemy.Initialize();
	fps.Initialize();

	//------------------------initialize---------------------------------

	//------------------------Load---------------------------------
	map.Load();
	//------------------------Load---------------------------------

	while (window.isOpen()) {
		//------------------------Update---------------------------------
		deltaTimer = clock.restart();
		float delta_time = deltaTimer.asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

		player.Update(delta_time,window,enemy);
		enemy.Update(delta_time);
		map.Update();
		fps.Update(delta_time);
		//------------------------Update---------------------------------

		//------------------------Draw---------------------------------
		window.clear(sf::Color::Black);
		map.Draw(window);
		fps.Draw(window);
		player.Draw(window);
		enemy.Draw(window);
		window.display();
		//------------------------Draw---------------------------------
	}
}