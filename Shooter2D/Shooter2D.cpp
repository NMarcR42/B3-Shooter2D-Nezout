// Shooter2D.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include"Bullet.h"
#include"Enemy.h"
#include"Player.h"
//#include"EnemyWave.h"
#include<vector>
#include<cstdlib>

//LENGTH OF VECTOR: |V| = sqrt(V.x^2 + V.y^2)
//NORMALIZE VECTOR: U = V / |V|

using namespace sf;

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(1920, 1080), "360 Shooter!", Style::Default);
	window.setFramerateLimit(60);

	//Music
	Music music;
	if (!music.openFromFile("ressources\\terran.ogg"))
	{
		std::cout << "error" << std::endl;
	}
	music.play();

	//Player
	Player testP1({ 500.0f, 500.0f });

	//Player hp bar
	RectangleShape hpBar;
	hpBar.setFillColor(Color::Red);
	hpBar.setSize(Vector2f((float)testP1.health * 2.f, 20.f));
	hpBar.setPosition(200.f, 10.f);

	//Health regen
	/*sf::Time micro = sf::microseconds(10000);
	sf::Time milli = sf::milliseconds(10);
	sf::Time second = sf::seconds(0.01f);*/


	sf::Clock shootTimer; //Player shoot cooldown
	sf::Clock spawnTimer; //Enemy spawn cooldown
	sf::Clock enemyAttackTimer; //enemy attack cooldown

	//Bullets
	Bullet b1;
	std::vector<Bullet> bullets;

	//Enemy
	Enemy enemySpawn("test");
	std::vector<Enemy> enemiesSpawn;



	//RectangleShape enemy;
	//enemy.setFillColor(Color::Magenta);
	//enemy.setSize(Vector2f(50.f, 50.f));
	int spawnCounter = 0;
	//
	//std::vector<RectangleShape> enemies;

	//Vectors
	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;
	Vector2f aimDirNorm;

	// Menu background  
	Texture texture;
	texture.loadFromFile("ressources\\ground1.jpg");
	//sf::RectangleShape rectangle;
	Sprite sprite(texture);

	//Score
	int score = 0;
	Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

	//std::ostringstream scorePoint;
	//scorePoint << "Score:" << score;

	Text text;
	text.setFont(font);
	text.setCharacterSize(100);
	//text.setColor(Color::Red);
	//text.setStyle(Text::Bold);
	text.setString("0");

	//camera movement
	View camera;
	camera.setSize(1920, 1080);


	while (window.isOpen() && testP1.health > 0)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//Update
		sf::Time elapsedShoot = shootTimer.getElapsedTime();
		sf::Time elapsedSpawn = spawnTimer.getElapsedTime();
		sf::Time elapsedEnemyAttack = enemyAttackTimer.getElapsedTime();
		//std::cout << elapsed.asSeconds() << std::endl;

		//Get position to fire the bullet and player rotation
		playerCenter = Vector2f(testP1.sprite.getPosition());
		mousePosWindow = Vector2f(Mouse::getPosition(window));
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = aimDir / float(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));

		float PI = 3.14159265f;
		float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
		//player.setRotation(deg + 90);
		testP1.sprite.setRotation(deg + 90);
		//Set Final Rotation of Ship
		//std::cout << deg << "\n";

		//Player movement
		Vector2f dir = { 0.0f, 0.0f };
		if (Keyboard::isKeyPressed(Keyboard::Z)) //Keyboard press Z-UP
			dir.y -= 1.0f;
		if (Keyboard::isKeyPressed(Keyboard::S)) //s-DOWN
			dir.y += 1.0f;
		if (Keyboard::isKeyPressed(Keyboard::Q)) //Q-LEFT
			dir.x -= 1.0f;
		if (Keyboard::isKeyPressed(Keyboard::D)) //D-RIGHT
			dir.x += 1.0f;

		// Player level management
		if (enemySpawn.enemyWave == 1)
		{
			testP1.SetDirection(dir, "level1");
			testP1.Update(1.0f / 60.0f, "level1");

		}
		//Set player level max for demo test
		if (enemySpawn.enemyWave >= 2)
		{
			testP1.SetDirection(dir, "level5");
			testP1.Update(1.0f / 60.0f, "level5");



		}
		enemySpawn.Update(1.0f / 60.0f);
		//enemySpawn.Move(Vector2f(testP1.sprite.getPosition()));
		//enemySpawn.sprite.move(testP1.sprite.getPosition());
		/*if (score >1500 and score < 4000)
		{
			testP1.SetDirection(dir, "level2");
			testP1.Update(1.0f / 60.0f, "level2");
		}
		if (score > 4000 and score < 10000)
		{
			testP1.SetDirection(dir, "level1");
			testP1.Update(1.0f / 60.0f, "level1");
		}*/
		//testP1.Update(1.0f / 60.0f, "level1");

		// Set camera to player position
		//camera.setCenter(testP1.sprite.getPosition());

		//Enemies

		/*if (enemy.getGlobalBounds().intersects(enemy.getGlobalBounds()))
		{
			std::cout << "The sprite have collided" << std::endl;
		}
		else
		{
			enemy.move(sf::Vector2f(0, -0.1));
		}*/
		//-------------
		/*if (spawnCounter < 4)
			spawnCounter++;*/

		if (elapsedSpawn.asSeconds() > 1, 5)
		{
			if (spawnCounter < 20 && enemiesSpawn.size() < 50)
			{
				//enemySpawn.sprite.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().x));
				//enemy.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().x));
				enemySpawn.zombieSprite.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().x));
				enemiesSpawn.push_back(enemySpawn);
				enemySpawn.Move(Vector2f(testP1.sprite.getPosition()));

				spawnCounter++;
				spawnTimer.restart();
			}

		}



		//Shooting + cooldown shoot
		if (elapsedShoot.asSeconds() > 1)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				b1.sprite.setPosition(playerCenter);
				b1.currVelocity = aimDirNorm * b1.maxSpeed;
				/*b1.sprite.setRotation(deg + 90);*/

				bullets.push_back(Bullet(b1));
				shootTimer.restart();
			}
		}

		//Update the hpbar with the current player hp
		hpBar.setSize(Vector2f((float)testP1.health * 20.f, 20.f));

		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].sprite.move(bullets[i].currVelocity);

			//Out of bounds
			if (bullets[i].sprite.getPosition().x < 0 || bullets[i].sprite.getPosition().x > window.getSize().x
				|| bullets[i].sprite.getPosition().y < 0 || bullets[i].sprite.getPosition().y > window.getSize().y)
			{
				//Delete bullet if out of the screen
				bullets.erase(bullets.begin() + i);
			}
			else
			{
				//Enemy collision
				for (size_t k = 0; k < enemiesSpawn.size(); k++)
				{
					//collision with bullet
					if (bullets[i].sprite.getGlobalBounds().intersects(enemiesSpawn[k].zombieSprite.getGlobalBounds()))
					{
						bullets.erase(bullets.begin() + i);

						//Damage to enemy
						if (enemySpawn.health > 0)
						{
							enemySpawn.TakeDamage(testP1.damageDeal);
						}
						//kill enemy
						if (enemySpawn.health <= 0)
						{
							enemiesSpawn.erase(enemiesSpawn.begin() + k);
							score++;
							enemySpawn.nbEnemyAlive--;

						}
						//Start new wave when all enemy are dead
						if (enemySpawn.nbEnemyAlive == 0)
						{
							enemySpawn.nbEnemyAlive = 20;
							spawnCounter = 0;
							enemySpawn.enemyWave++;
							enemySpawn.health = enemySpawn.maxHealth + 2;
							enemySpawn.maxHealth = enemySpawn.maxHealth + 2;
						}

						break;
					}

				}

			}
		}
		//Enemy collision
		for (size_t k = 0; k < enemiesSpawn.size(); k++)
		{
			//collision with palyer
			if (elapsedShoot.asSeconds() > 1)
			{
				if (enemiesSpawn[k].zombieSprite.getGlobalBounds().intersects(testP1.sprite.getGlobalBounds()))
				{
					if (testP1.health > 0)
					{
						testP1.TakeDamage(enemySpawn.dmg);
					}
					shootTimer.restart();
					break;
				}
			}
		}

		//rect.update(dt);
		text.setString(std::to_string(score));


		//Draw
		window.clear();
		window.draw(sprite);




		for (size_t i = 0; i < enemiesSpawn.size(); i++)
		{
			std::cout << enemiesSpawn.size() << std::endl;
			window.draw(enemiesSpawn[i].zombieSprite);
			enemiesSpawn[i].Move(Vector2f(testP1.sprite.getPosition()));
		}

		window.draw(hpBar);

		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i].sprite);
		}
		//window.draw(rect);
		window.draw(text);

		//window.draw(player);
		enemySpawn.Draw(window);
		testP1.Draw(window);

		//window.setView(camera);
		//window.setView(window.getDefaultView());
		window.display();
	}

	return 0;
}


