#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"EnemyAnimation.h"

class Enemy
{
private:
	enum class AnimationIndex
	{
		WalkinpZergling,
		WalkingHydralisk,
		Count
	};
public:
	Enemy(sf::String test)
	{

		zombieSprite = sf::Sprite(zombieTexture);
		zombieSprite.setTextureRect({ 0,0,37,37 });

		// setting frame level 1 marine
		walk[int(AnimationIndex::WalkinpZergling)] = EnemyAnimation(0, 0, 37, 37, "zergling");
		walk[int(AnimationIndex::WalkingHydralisk)] = EnemyAnimation(320, 0, 40, 40, "zergling"); //(64, 128, 64, 64)
	}

	sf::Texture zombieTexture;
	sf::Sprite zombieSprite;
	int health = 10;
	int maxHealth = 10;
	int dmg = 1;
	int nbEnemyAlive = 20;

	sf::Vector2f zombiePosition;
	sf::Vector2f playerPosition;
	sf::Vector2f direction;
	sf::Vector2f normalizedDir;


	int enemyWave = 1;
	int xPos;
	int yPos;
	float speed;
	void Move(const sf::Vector2f& playerposition);

	void Draw(sf::RenderTarget& rt)const
	{
		rt.draw(zombieSprite);
	}

	void Update(float dt)
	{
		walk[int(currentAnim)].Update(dt);
		walk[int(currentAnim)].ApplyToSprite(zombieSprite);
	}

	//Enemy get damage from player
	void TakeDamage(int damage);

	//Upgrade HP each next wave
	void UpgradeHPStat(int wave);

	void Evolve(int currentWave)
	{

	}

private:
	/*static constexpr float speed = 100.0f;
	sf::Vector2f pos;
	sf::Vector2f vel = { 0.0f, 0.0f };*/
	EnemyAnimation walk[int(AnimationIndex::Count)];
	AnimationIndex currentAnim = AnimationIndex::WalkinpZergling;

};

