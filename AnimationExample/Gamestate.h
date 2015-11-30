#pragma once
#include "Player.h"
#include "Enemy.h"
#include "projectiles.h"
#include "Background.h"
#include <vector>

/*
GameState is the 'database' of the game.

It's a central hub to allow all of the objects
in the game communicate with one another.

It's also a good place to manage spawning new objects!
*/


class GameState
{
	Player player; 	// store all of our gameobjects
	Border border;
	Space space1;
	Space space2;
	Asteroid asteroid1;
	Asteroid asteroid2;
	Nebula nebula1;
	Nebula nebula2;
	Player playership;
	PlanetBob planetBob;
	std::vector<Enemy> enemyships;
	std::vector<Projectile> bullets;
	
public:
	void start()
	{
		space2.x = 800;
		asteroid2.x = 2024;
		nebula2.x = 2000;
		nebula2.width = 600;
		nebula2.textureName = "Nebula2";
	}

	// Parameters may match the constructor for the bullet
	void makeBullet(float x, float y, float dx, float dy, float lifespan)
	{
		for (int i = 0; i < bullets.size(); ++i)
		{
			if (!bullets[i].isActive) // Find an empty spot in our vector
			{
				bullets[i] = Projectile(x, y, dx, dy, lifespan);
				return;
			}
		}
		// if there is no empty spot, generate a new bullet into the vector
		bullets.push_back(Projectile(x, y, dx, dy, lifespan));
	}

	// Mimic the makeBullet pattern- 
	void makeExplosion()
	{
		
	}
	void makeEnemy(float x, float y, float dx, float dy, float lifespan)
	{
		for (int i = 0; i < enemyships.size(); ++i)
		{
			if (!enemyships[i].isActive) 
			{
				enemyships[i] = Enemy(x, y, dx, dy, lifespan);
				return;
			}
		}		
		enemyships.push_back(Enemy(x, y, dx, dy, lifespan));
	}


	// MUY IMPORTANTE!
	GameState()
	{
		// Setup the gamestate pointer that all of the gameobjects share!
		GameObject::gs() = this;
	}
	// Update objects, check for collision,
	// respond to events or special logic that changes how the game plays (ie. player is dead)
	void update()
	{
		space1.update();
		space2.update();
		asteroid1.update();
		asteroid2.update();
		nebula1.update();
		nebula2.update();
		planetBob.update();

		if (player.isActive)
			playership.update();

		// example useful for determining when to spawn a new wave of enemies.
		int nBulletsActive = 0;

		for (int i = 0; i < bullets.size(); ++i)
			if (bullets[i].isActive)
			{
				bullets[i].update();
				if (player.isActive)
					doCollision(player, bullets[i]);
			}
			else nBulletsActive++;


			//Got to Fix this!!!!!!!!!!!!
			int nEnemyshipsActive = 0;

			if (nEnemyshipsActive == 0)
			{
				for (int i = 0; i < enemyships.size(); ++i)
					for (int j = 0; j < bullets.size(); ++j)
					if (enemyships[i].isActive)
					{
						enemyships[i].update();
						if (player.isActive)
							doCollision(enemyships[i], bullets[j]);
					}
			}
					else nEnemyshipsActive++;
			// Collision detection between two objects of the same type
			for (int i = 0; i + 1 < bullets.size(); ++i)
				for (int j = i + 1; j < bullets.size(); ++j)
				{
					doCollision(bullets[i], bullets[j]);
				}

			doCollision(border, playership);
			
	}

	// DRaw everything now!
	void draw()
	{
		space1.draw();
		space2.draw();
		planetBob.draw();
		asteroid1.draw();
		asteroid2.draw();
		nebula1.draw();
		nebula2.draw();
		
		if (player.isActive) playership.draw();

		for (int i = 0; i < bullets.size(); ++i)
			if (bullets[i].isActive)
				bullets[i].draw();
		for (int i = 0; i < enemyships.size(); ++i)
			if (enemyships[i].isActive)
				enemyships[i].draw();

		
	}

	// Needs some way to 'spawn/destroy' bullets/enemies.

	// Changes in gameplay happen here.
};