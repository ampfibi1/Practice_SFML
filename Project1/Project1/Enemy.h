#pragma once
#include<SFML/Graphics.hpp>

class Enemy
{
private:
	sf::CircleShape  enemy_box;
	float box_speed;
public:
	void Initialize();
	void Update(float delta_time);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
};

