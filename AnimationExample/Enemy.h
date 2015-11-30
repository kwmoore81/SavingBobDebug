#pragma once
#include "GameObject.h"
#include "GameState.h"
#include "Player.h"
#include "projectiles.h"



class Enemy : public Player
{
public:
	float eVelx, eVely; // velocity of our bullet
	float eLifetime; // how long it lasts
	
	Enemy(float e_x, float e_y, float ex, float ey, float eLifespan)
	{
		
		x = e_x;
		y = e_y;

		eVelx = ex;
		eVely = ey;

		eLifetime = eLifespan;
		
		width = 128; height = 128; centered = true; color = WHITE;
		textureName = "Enemy";
		animationName = "eThrusters";
		
	}

	virtual void onCollision(GameObject &go, float distance)
	{
		width = 128; height = 128; centered = true; color = WHITE;
		animationName = "Boom";
		textureName = "Explosion";
	}

	virtual void update()
	{
		
		eLifetime -= sfw::getDeltaTime();
		isActive = eLifetime > 0; // the bullet is no longer active when the lifetime reduces to 0

								 // Euler Integration to move our bullet
		x += eVelx * sfw::getDeltaTime();
		y += eVely * sfw::getDeltaTime();
		
		//GameObject::update();
		
		if (animTimer > getAnimationDuration(textureName, animationName))
		{
			animTimer = 0;
			animationName = "eThrusters";
		}
		x--;

		
	}

	//virtual void draw()
	//{

	//	sfw::drawTexture(getTexture("Enemy"), 650, 300, 128, 128, 0, true, 0, WHITE);
	//	
	//}

};
