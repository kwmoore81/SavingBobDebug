#pragma once
#include "GameObject.h"
#include "GameState.h"
#include "Player.h"



class Enemy : public Player
{
public:
	float velx, vely; // velocity of our bullet
	float lifetime; // how long it lasts
	
	Enemy(float a_x, float a_y, float dx, float dy, float lifespan)
	{
		
		x = a_x;
		y = a_y;

		velx = dx;
		vely = dy;

		lifetime = lifespan;
		
		width = 128; height = 128; centered = true; color = WHITE;
		textureName = "Enemy";
		animationName = "eThrusters";
		
	}

	virtual void onCollision(GameObject &go, float distance)
	{
		// we could react to collisions here
	}

	virtual void update()
	{
		
		lifetime -= sfw::getDeltaTime();
		isActive = lifetime > 0; // the bullet is no longer active when the lifetime reduces to 0

								 // Euler Integration to move our bullet
		x += velx * sfw::getDeltaTime();
		y += vely * sfw::getDeltaTime();
		
		GameObject::update();
		
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
