#include "Math.h"

bool Math::isCollision(sf::Vector2f player, sf::Vector2f enemy)
{
	if (enemy.x<player.x + 50.f && enemy.x + 50.f > player.x &&
		enemy.y< player.y + 50.f && enemy.y + 50.f > player.y)
	{
		return true;
	}
	return false;
}

