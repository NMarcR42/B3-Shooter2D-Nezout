#include "Enemy.h"

// Make ennemy follow player
void Enemy::Move(const sf::Vector2f& playerpositions)
{

	xPos = zombieSprite.getPosition().x;
	yPos = zombieSprite.getPosition().y;

	zombiePosition = sf::Vector2f(xPos, yPos);

	playerPosition = playerpositions;


	direction = playerPosition - zombiePosition;
	normalizedDir = direction / float(sqrt(pow(direction.x, 2) + pow(direction.y, 2)));
	speed = 2;

	//Rotate the enemy relative to player position
	const float PI = 3.14159265;

	float dx = zombiePosition.x - playerPosition.x;
	float dy = zombiePosition.y - playerPosition.y;

	float rotation = (atan2(dy, dx)) * 180 / PI;

	zombieSprite.setRotation(rotation + 90);

	sf::Vector2f currentSpeed = normalizedDir * speed;

	zombieSprite.move(currentSpeed);
}

void Enemy::TakeDamage(int recieveDmg)
{
	health = health - recieveDmg;
}
