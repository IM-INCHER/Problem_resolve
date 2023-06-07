#include "stdafx.h"
#include "Obstacle.h"

Tree::Tree()
{
	pos.x = 120;
	pos.y = 20;
	pos.z = 0;

	speed = 1.f;

	collisionBox.left = 120;
	collisionBox.top = 20;
	collisionBox.right = 123;
	collisionBox.bottom = 17;
}

void Tree::Init()
{
	pos.x = 120;
	pos.y = 20;
	pos.z = 0;

	collisionBox.left = 120;
	collisionBox.top = 20;
	collisionBox.right = 123;
	collisionBox.bottom = 17;
}

void Tree::Update()
{
	pos.x -= speed;

	collisionBox.left = pos.x;
	collisionBox.top = pos.y;
	collisionBox.right = pos.x + 3;
	collisionBox.bottom = pos.y - 3;
}

void Tree::Render()
{
	RENDERMANAGER->Print(pos.x + 1, pos.y, Color::BROWN);
	RENDERMANAGER->Print(pos.x, pos.y - 1, Color::YELLOW);
	RENDERMANAGER->Print(pos.x + 1, pos.y - 1, Color::YELLOW);
	RENDERMANAGER->Print(pos.x + 2, pos.y - 1, Color::YELLOW);
	RENDERMANAGER->Print(pos.x , pos.y - 2, Color::YELLOW);
	RENDERMANAGER->Print(pos.x + 1, pos.y - 2, Color::YELLOW);
	RENDERMANAGER->Print(pos.x + 2, pos.y - 2, Color::YELLOW);
	RENDERMANAGER->Print(pos.x + 1, pos.y - 3, Color::YELLOW);
}

bool Tree::FreeCheck()
{
	if (pos.x < -3) return true;
	return false;
}

Rock::Rock()
{
	pos.x = 120;
	pos.y = 19;
	pos.z = 0;

	speed = 1.f;

	collisionBox.left = 120;
	collisionBox.top = 19;
	collisionBox.right = 124;
	collisionBox.bottom = 17;
}

void Rock::Init()
{
	pos.x = 120;
	pos.y = 19;
	pos.z = 0;

	collisionBox.left = 120;
	collisionBox.top = 19;
	collisionBox.right = 124;
	collisionBox.bottom = 17;
}

void Rock::Update()
{
	pos.x -= speed;

	collisionBox.left = pos.x;
	collisionBox.top = pos.y;
	collisionBox.right = pos.x + 5;
	collisionBox.bottom = pos.y - 2;
}

void Rock::Render()
{
	for (int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 2; j++)
			RENDERMANAGER->Print(pos.x + i, pos.y + j, Color::DARKGRAY);
	}
}

bool Rock::FreeCheck()
{
	if (pos.x < -5) return true;
	return false;
}
