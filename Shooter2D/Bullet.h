#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<vector>
#include<cstdlib>

using namespace sf;

class Bullet
{
public:
	CircleShape shape;
	Vector2f currVelocity;
	float maxSpeed;
	sf::Sprite sprite;

	Bullet(float radius = 5.f)
		: currVelocity(0.f, 0.f), maxSpeed(8.f)
	{
		this->shape.setRadius(radius);
		this->shape.setFillColor(Color::Black);
		texture.loadFromFile("ressources\\bullet.jpg");
		sprite = sf::Sprite(texture);
	}
	void ApplyToSprite(sf::Sprite& sp)const
	{
		sp.setTexture(texture);
	}
	void Draw(sf::RenderTarget& rt)const
	{
		rt.draw(sprite);
	}
private:
	sf::Texture texture;
};

