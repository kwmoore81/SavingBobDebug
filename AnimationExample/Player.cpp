#include "GameState.h"
#include "GameObject.h"
#include "Player.h"


void Player::update()

	{


		fireDelay -= sfw::getDeltaTime();
		// example of switching between animations
		if (sfw::getKey(257) && fireDelay < 0)
		{
			fireDelay = rateOfFire;
			gs()->makeBullet(x, y, 800, 0, 4.f); // Now we can use this to draw stuff!
		}
		
		gs()->makeEnemy(650, 300, 0, 0, 4.f); // Now we can use this to draw stuff!
		// example of switching between animations
		/*if (sfw::getKey(' '))
		{
		animTimer = 0;
		animationName = "Thrusters";
		}*/
		GameObject::update();
		if (animTimer > getAnimationDuration(textureName, animationName))
		{
			animTimer = 0;
			animationName = "Thrusters";
		}

		sdt = sfw::getDeltaTime() * speed;
		if (sfw::getKey('W')) y += sdt * 3;
		if (sfw::getKey('S')) y -= sdt * 3;
		if (sfw::getKey('A')) x -= sdt * 3;
		if (sfw::getKey('D')) x += sdt * 3;

		}
