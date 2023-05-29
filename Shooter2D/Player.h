#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"PlayerAnimation.h"


class Player
{
private:
	enum class AnimationIndex
	{
		WalkingUpMarine,
		WalkingDownMarine,
		WalkingLeftMarine,
		WalkingRightMarine,
		WalkingUpGoliath,
		WalkingDownGoliath,
		WalkingLeftGoliath,
		WalkingRightGoliath,
		WalkingUpGhost,
		WalkingDownGhost,
		WalkingLeftGhost,
		WalkingRightGhost,
		WalkingUpWrath,
		WalkingDownWrath,
		WalkingLeftWrath,
		WalkingRightWrath,
		WalkingUpBattlecruiser,
		WalkingDownBattlecruiser,
		WalkingLeftBattlecruiser,
		WalkingRightBattlecruiser,

		Count
	};
public:
	//RectangleShape hpBar;
	sf::Vector2f pos2;
	sf::Sprite sprite;
	int health = 5;
	int damageDeal = 5;
	int test = 1;
	Player(const sf::Vector2f& pos)
		:
		pos(pos)
	{
		pos2 = pos;
		sprite = sf::Sprite(texture);
		sprite.setTextureRect({ 0,0,64,64 });


		// setting frame level 1 marine
		walk[int(AnimationIndex::WalkingUpMarine)] = PlayerAnimation(0, 256, 64, 64, "up", "marine");
		//walk[int(AnimationIndex::WalkingDownMarine)] = PlayerAnimation(0, 256, 64, 64, "down", "marine"); 
		//walk[int(AnimationIndex::WalkingLeftMarine)] = PlayerAnimation(256, 0, 64, 64,"left", "marine");
		//walk[int(AnimationIndex::WalkingRightMarine)] = PlayerAnimation(256, 376, 64, 64,"right", "marine");

		// setting frame level 2 Goliath
		walk[int(AnimationIndex::WalkingUpGoliath)] = PlayerAnimation(64, 0, 80, 80, "up", "goliath");
		//walk[int(AnimationIndex::WalkingDownGoliath)] = PlayerAnimation(0, 64, 64, 64, "down", "goliath");
		//walk[int(AnimationIndex::WalkingLeftGoliath)] = PlayerAnimation(64, 0, 64, 64, "left", "goliath");
		//walk[int(AnimationIndex::WalkingRightGoliath)] = PlayerAnimation(64, 192, 64, 64, "right", "goliath"); 

		// setting frame level 3 Ghost
		walk[int(AnimationIndex::WalkingUpGhost)] = PlayerAnimation(64, 0, 64, 64, "up", "ghost");
		//walk[int(AnimationIndex::WalkingDownGhost)] = PlayerAnimation(0, 64, 64, 64, "down", "ghost");
		//walk[int(AnimationIndex::WalkingLeftGhost)] = PlayerAnimation(64, 0, 64, 64, "left", "ghost");
		//walk[int(AnimationIndex::WalkingRightGhost)] = PlayerAnimation(64, 192, 64, 64, "right", "ghost");

		// setting frame level 4 Wrath
		walk[int(AnimationIndex::WalkingUpWrath)] = PlayerAnimation(64, 0, 64, 64, "up", "wrath");
		//walk[int(AnimationIndex::WalkingDownWrath)] = PlayerAnimation(0, 64, 64, 64, "down", "wrath"); 
		//walk[int(AnimationIndex::WalkingLeftWrath)] = PlayerAnimation(64, 0, 64, 64, "left", "wrath");
		//walk[int(AnimationIndex::WalkingRightWrath)] = PlayerAnimation(64, 192, 64, 64, "right", "wrath"); 

		// setting frame level 5 Battlecruiser
		walk[int(AnimationIndex::WalkingUpBattlecruiser)] = PlayerAnimation(64, 0, 64, 64, "up", "battlecruiser");
		//walk[int(AnimationIndex::WalkingDownBattlecruiser)] = PlayerAnimation(0, 64, 64, 64, "down", "battlecruiser"); 
		//walk[int(AnimationIndex::WalkingLeftBattlecruiser)] = PlayerAnimation(64, 0, 64, 64, "left", "battlecruiser"); 
		//walk[int(AnimationIndex::WalkingRightBattlecruiser)] = PlayerAnimation(64, 192, 64, 64, "right", "battlecruiser"); 
	}
	void Draw(sf::RenderTarget& rt)const
	{
		rt.draw(sprite);
	}
	// Catch the player direction 
	void SetDirection(const sf::Vector2f& dir, sf::String level)
	{
		vel = dir * speed;

		if (level == "level1")
		{
			if (dir.x > 0.0f)
			{
				currentAnim = AnimationIndex::WalkingUpMarine;
			}
			if (dir.x < 0.0f)
			{
				currentAnim = AnimationIndex::WalkingUpMarine;
			}
			if (dir.y < 0.0f)
			{
				currentAnim = AnimationIndex::WalkingUpMarine;
			}
			if (dir.y > 0.0f)
			{
				currentAnim = AnimationIndex::WalkingUpMarine;
			}
		}
		//Set last level player for test
		if (level == "level5")
		{
			if (test == 1)
			{
				//*************************************
				//Player stats level max for demo test
				health = 25;
				damageDeal = 25;
				//*************************************
				test--;
			}
			if (dir.x > 0.0f)
			{

				currentAnim = AnimationIndex::WalkingUpGoliath; //origin right
			}
			if (dir.x < 0.0f)
			{
				currentAnim = AnimationIndex::WalkingUpGoliath; //origin left
			}
			if (dir.y < 0.0f)
			{
				currentAnim = AnimationIndex::WalkingUpGoliath; //origin up
			}
			if (dir.y > 0.0f)
			{
				currentAnim = AnimationIndex::WalkingUpGoliath; //origin down
			}
		}
		//if(level == "level3")
		//{ 
		//}
		//if (level == "level4")
		//{
		//}
		//if (level == "level5")
		//{
		//}
	}

	void Update(float dt, sf::String level)
	{
		pos += vel * dt;
		// Fix animation when player reach level 4 and 5 because of the sprite file
		if (level != "level5")
		{
			walk[int(currentAnim)].Update(dt);
		}
		//walk[int(currentAnim)].Update(dt);
		walk[int(currentAnim)].ApplyToSprite(sprite);
		sprite.setPosition(pos);
	}

	//void PlayerPower(sf::String level);


	//void Health()
	//{

	//}
	void TakeDamage(int getDamage);

	/*void DamageDone()
	{

	}*/

private:
	static constexpr float speed = 300.0f;
	sf::Vector2f pos;
	sf::Vector2f vel = { 0.0f, 0.0f };
	sf::Texture texture;

	PlayerAnimation walk[int(AnimationIndex::Count)];
	AnimationIndex currentAnim = AnimationIndex::WalkingUpMarine;
};

