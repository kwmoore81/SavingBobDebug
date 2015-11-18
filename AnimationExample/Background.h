#pragma once
#include "GameObject.h"


class Space : public GameObject
{
public:

	Space()
	{
		x = 0; y = 600; width = 800; height = 600; centered = false; color = WHITE;
		textureName = "Space";

	}
	virtual void update()
	{

		x -= 1;

		if (x <= -width)
		{
			x = width;
		}
	}
	};

class Asteroid : public GameObject
{
public:

	Asteroid()
	{
		x = 0; y = 600; width = 2024; height = 600; centered = false; color = 0x777700ff;
		textureName = "Asteroid Belt";

	}
	virtual void update()
	{

		x -= 3;

		if (x <= -width)
		{
			x = 800;
		}
	}
};

class Nebula : public GameObject
{
public:

	Nebula()
	{
		x = 0; y = 600; width = 1250; height = 600; centered = false; color = 0xffffff22;
		textureName = "Nebula";

	}
	virtual void update()
	{

		x -= 8;

		if (x <= -width)
		{
			x = width;
		}
	}
};

class Border : public GameObject
{
public:

	Border()
	{
		width = 800; height = 600; centered = true;
	}

};
