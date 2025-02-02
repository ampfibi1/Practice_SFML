#include "Bullet.h"

sf::Vector2f normalization(sf::Vector2f d) {
	float mag = sqrt(d.x * d.x + d.y * d.y);
	return d / mag; 
}
Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}




void Bullet::Initialize(const sf::Vector2f& position, sf::Vector2f& target)
{
	shape = sf::CircleShape(20.f, 4);
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Blue);
	shape.setRotation(45);

	direction = normalization(target - position);
	bullet_speed = 200.f;
}

void Bullet::Update(float deltatime)
{
	shape.setPosition(shape.getPosition() + direction * deltatime * bullet_speed);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);	
}

sf::Vector2f Bullet::getPosition()
{
	return shape.getPosition();
}
