#pragma once
#include "Background.h"

int menuSelection = 1;
class MenuState
{
	Space space1;
	Space space2;
	Asteroid asteroid1;
	Asteroid asteroid2;
	Nebula nebula1;
	Nebula nebula2;
	Play play;
	Exit exit;
	Credits credits;
	SavingTitle savingTitle;
	BobTitle bobTitle;
	PlanetBob planetBob;


public:
	void menuLayout()
	{
		space2.x = 800;
		asteroid2.x = 2024;
		nebula2.x = 2000;
		nebula2.width = 600;
		nebula2.textureName = "Nebula2";

	}

	void update()
	{
		space1.update();
		space2.update();
		asteroid1.update();
		asteroid2.update();
		nebula1.update();
		nebula2.update();
		play.update();
		exit.update();
		credits.update();
		planetBob.update();
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < play.x + 64 && sfw::getMouseX() > play.x -64 && sfw::getMouseY() < play.y + 64 && sfw::getMouseY() > play.y - 64)
			{
				menuSelection = 2;
			}
		}
		
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < exit.x + 64 && sfw::getMouseX() > exit.x - 64 && sfw::getMouseY() < exit.y + 64 && sfw::getMouseY() > exit.y - 64)
			{
				menuSelection = 4;
			}
		}
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < credits.x + 64 && sfw::getMouseX() > credits.x - 64 && sfw::getMouseY() < credits.y + 64 && sfw::getMouseY() > credits.y - 64)
			{
				menuSelection = 3;
			}
		}
			
	}
	void draw()
	{
		space1.draw();
		space2.draw();
		planetBob.draw();
		asteroid1.draw();
		asteroid2.draw();
		savingTitle.draw();
		bobTitle.draw();
		nebula1.draw();
		nebula2.draw();
		play.draw();
		exit.draw();
		credits.draw();
	
		sfw::drawTexture(getTexture("Crosshair"), sfw::getMouseX(), sfw::getMouseY(), 64, 64, 0, true, 0, WHITE);
	}
};