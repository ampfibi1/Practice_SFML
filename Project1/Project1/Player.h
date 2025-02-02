#pragma once
#include<SFML/Graphics.hpp>
#include"Bullet.h"
#include"Math.h"
#include"Enemy.h"

class Player
{
private:
	sf::CircleShape box;
	float box_speed; 
	std::vector<Bullet> bullets;
	float bullet_speed; 
	float maxFireRate;
	sf::Clock clock_fire_rate;
	float fire_rate_time ;
public:
	void Initialize();
	void Update(float delta_time,sf::RenderWindow& window,Enemy enemy);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
};

