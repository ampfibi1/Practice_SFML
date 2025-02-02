#include "Enemy.h"

void Enemy::Initialize()
{
	enemy_box = sf::CircleShape(50.f, 4);
	enemy_box.setFillColor(sf::Color::Red);
	enemy_box.setPosition(sf::Vector2f(200, 300));
	enemy_box.setRotation(45);
}

void Enemy::Update(float delta_time)
{
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(enemy_box);
}

sf::Vector2f Enemy::getPosition()
{
	return enemy_box.getPosition();
}
