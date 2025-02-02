#pragma once
#include<SFML/Graphics.hpp>

class Bullet
{
public :
	float speed; 
private : 
	sf::CircleShape shape; 
	sf::Vector2f direction; 
	float bullet_speed ;
public : 
	Bullet();
	~Bullet();

	void Initialize(const sf::Vector2f& position, sf::Vector2f& target);
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();

	inline const sf::FloatRect GetGlobalBound() { return shape.getGlobalBounds(); }
};

