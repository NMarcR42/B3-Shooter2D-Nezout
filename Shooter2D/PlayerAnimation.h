#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"

class PlayerAnimation
{
public:

	PlayerAnimation() = default;
	PlayerAnimation(int x, int y, int width, int height, sf::String dir, sf::String level)
	{
		// Niveeau 1: Marine
		if (level == "marine")
		{
			if (dir == "up")
			{
				static constexpr int nFrames = 8;
				texture.loadFromFile("ressources\\marine.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { x ,y + i * width,width,height };
				}
			}
			if (dir == "down")
			{
				static constexpr int nFrames = 8;
				texture.loadFromFile("marine.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { x ,y + i * width,width,height };
				}
			}
			if (dir == "left")
			{
				static constexpr int nFrames = 8;
				texture.loadFromFile("ressources\\marine.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { x ,y + i * width,width,height };
				}
			}
			if (dir == "right")
			{
				static constexpr int nFrames = 9;
				texture.loadFromFile("ressources\\marine.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { x ,y + i * width,width,height };
				}
			}
		}

		// Niveau 2 : Goliath
		if (level == "goliath")
		{
			if (dir == "up")
			{
				static constexpr int nFrames = 1;
				texture.loadFromFile("ressources\\battlecruiser_down.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { 0,y,width,height };
				}
			}
			if (dir == "down")
			{
				static constexpr int nFrames = 1;
				texture.loadFromFile("ressources\\battlecruiser.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { 0,y,width,height };
				}
			}
			if (dir == "left")
			{
				static constexpr int nFrames = 1;
				texture.loadFromFile("ressources\\battlecruiser.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { 0,y,width,height };
				}
			}
			if (dir == "right")
			{
				static constexpr int nFrames = 1;
				texture.loadFromFile("ressources\\battlecruiser.png");
				for (int i = 0; i < nFrames; i++)
				{
					frames[i] = { 0,y,width,height };
				}
			}
		}


		//// Niveau 3 : Ghost
		//if (dir == "up")
		//{
		//	static constexpr int nFrames = 3;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "down")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "left")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "right")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}

		//// Niveau 4 : Wrath
		//// if (dir == "up")
		//{
		//	static constexpr int nFrames = 3;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "down")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "left")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "right")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}

		//// Niveau 5 : Battlecruiser
		//if (dir == "up")
		//{
		//	static constexpr int nFrames = 3;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "down")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "left")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		//if (dir == "right")
		//{
		//	static constexpr int nFrames = 5;
		//	texture.loadFromFile("marine.png");
		//	for (int i = 0; i < nFrames; i++)
		//	{
		//		frames[i] = { x + i * width,y,width,height };
		//	}
		//}
		/*texture.loadFromFile("marine.png");
		for (int i = 0; i < nFrames; i++)
		{
			frames[i] = { x + i * width,y,width,height };
		}*/
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

