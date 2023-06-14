#include "stdafx.h"
#include "BgObjects.h"

Sun::Sun(float x, float y, float z, float speed)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	this->speed = speed;
	this->initSpeed = speed;
}

void Sun::Init()
{
	speed = initSpeed;
}

void Sun::Update()
{
	pos.x -= speed;

	if (pos.x < -3) pos.x = 120;
}


void Sun::Render()
{
	for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 3; j++)
			RENDERMANAGER->Print(pos.x + i, pos.y + j, Color::LIGHTRED);
	}
}

Sun::~Sun()
{
}

//==============================================================================================

void Grand::Init()
{
}

void Grand::Update()
{
}

void Grand::Render()
{
	for (int i = 0; i < 120; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			RENDERMANAGER->Print(i, 21 + j, BROWN);
		}
	}

}

Cloud::Cloud(float x, float y, float z, float speed)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	this->speed = speed;
	this->initSpeed = speed;
}

void Cloud::Init()
{
	speed = initSpeed;
}

void Cloud::Update()
{
	pos.x -= speed;

	if (pos.x < -4) pos.x = 120;
}

void Cloud::Render()
{
	for (int i = 0; i < 3; i++)
	{
		RENDERMANAGER->Print(pos.x + i, pos.y, Color::WHITE);
	}

	for (int i = 0; i < 5; i++)
	{
		RENDERMANAGER->Print(pos.x + i - 1, pos.y + 1, Color::WHITE);
	}
}

Mountain::Mountain(float x, float y, float z, float speed)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	this->speed = speed;
	this->initSpeed = speed;
}

void Mountain::Init()
{
	speed = initSpeed;
}

void Mountain::Update()
{
	pos.x -= speed;

	if (pos.x < -30) pos.x = 120;
}

void Mountain::Render()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 32 - i * 2; j++)
		RENDERMANAGER->Print(pos.x + j + i, pos.y - i, Color::GREEN);
	}
}