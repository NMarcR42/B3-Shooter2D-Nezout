#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"

class EnemyAnimation
{
public:

	EnemyAnimation() = default;
	EnemyAnimation(int x, int y, int width, int height, sf::String level)
	{
		//Zerg: Zergling
		if (level == "zergling")
		{

			static constexpr int nFrames = 6;
			texture.loadFromFile("ressources\\zergling.png");
			for (int i = 0; i < nFrames; i++)
			{
				frames[i] = { x ,y + i * width,width,height };
			}
		}

		//Zerg : Hydralisk
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}

		////Protoss : Zealot
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}

		////Protoss : Dark Templar
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}

		////Zerg : Ultralisk
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}

		////Zerg : Mutalisk
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}

		////Zerg : Devorer
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}
		////Zerg : Guardian
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}

		////Zerg Boss : Kerrigan
		//if (level == "goliath")
		//{
		//	if (dir == "up")
		//	{
		//		static constexpr int nFrames = 1;
		//		texture.loadFromFile("battlecruiser.png");
		//		for (int i = 0; i < nFrames; i++)
		//		{
		//			frames[i] = { 0,y,width,height };
		//		}
		//	}
		//}
	}

	void ApplyToSprite(sf::Sprite& sp)
	{
		sp.setTexture(texture);
		sp.setTextureRect(frames[iFrame]);
	}

	void Update(float dt)
	{
		time += dt;
		while (time >= holdTime)
		{
			time -= holdTime;
			Advance();
		}
	}
private:
	void Advance()
	{
		if (++iFrame >= nFrames)
		{
			iFrame = 0;
		}
	}
private:
	static constexpr float holdTime = 0.1f;
	static constexpr int nFrames = 10;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iFrame = 0;
	float time = 0.0f;
};

