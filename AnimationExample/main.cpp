#include <sfwdraw.h>
#include "AssetLibrary.h"
#include "Player.h"
#include <vector>
#include "GameState.h"

void main()
{
	sfw::initContext(800, 600, "Saving Bob");
	sfw::setBackgroundColor(BLACK);	
	
	loadTexture("Space", "../res/space800x600.jpg", 1, 1);
	loadTexture("Asteroid Belt", "../res/asteroidbelt.png", 1, 1);
	loadTexture("Nebula", "../res/nebula.png", 1, 1);
	loadTexture("Nebula2", "../res/nebula2.png", 1, 1);
	loadTexture("Player", "../res/playership.png", 8, 1); 
	loadTexture("Bullet", "../res/bullet.png", 1, 1);
	loadTexture("Enemy", "../res/enemyship.png", 9, 1);
	addAnimation("Player", "Thrusters", {0,1,2,3,4,5,6,7});
	addAnimation("Enemy", "eThrusters", { 0,1,2,3,4,5,6,7,8 });
	
	GameState game;
	game.start();
	while (sfw::stepContext())
	{
		
		//switch ()
		//{
		//case MENU:
		//	menu.update();
		//	menu.draw();
		//case GAME:
		game.update(); // Do the thing!
		game.draw();   // Draw it!
					   //}
		
	}
	
	sfw::termContext();
}

	

