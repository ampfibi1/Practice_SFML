#include "Player.h"

void Player::Initialize()
{
	box = sf::CircleShape(50.f, 4);
	box.setFillColor(sf::Color::White);
	box.setRotation(45);
	box_speed = 1000.f;
	bullet_speed = 200.f;
	maxFireRate = .15f;
	fire_rate_time = 0;
}

void Player::Update(float delta_time, sf::RenderWindow& window,Enemy enemy)
{
	sf::Vector2f pos = box.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pos.x += box_speed * delta_time;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pos.x -= box_speed * delta_time;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pos.y -= box_speed * delta_time;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) pos.y += box_speed * delta_time;
	box.setPosition(pos);

	fire_rate_time += delta_time;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fire_rate_time >= maxFireRate) {
		bullets.push_back(Bullet());
		int index = bullets.size() - 1;
		sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(window));

		bullets[index].Initialize(box.getPosition(), mouse_pos);

		fire_rate_time = 0;
	}

	int i = 0;
	for (auto& bullet : bullets) {
		bullet.Update(delta_time);
		bool check_Collision = Math::isCollision(bullet.getPosition(), enemy.getPosition());
		if (check_Collision)
			bullets.erase(bullets.begin() + i);
		++i;
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(box);
	for (auto x : bullets) x.Draw(window);
}

sf::Vector2f Player::getPosition()
{
	return box.getPosition();
}
