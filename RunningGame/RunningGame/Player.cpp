#include "stdafx.h"
#include "Player.h"

void Player::Init()
{
	pos.x = 20;
	pos.y = 18;
	pos.z = 0;

	isRight = false;

	state = State_Run;

	jumpPower = 1.f;
	gravity = 0;
	gravityPower = 0.08f;

	collisionBox.left = 20;
	collisionBox.right = 23;
	collisionBox.top = 20;
	collisionBox.bottom = 18;
}

void Player::Update()
{
	count++;

	collisionBox.top = pos.y;
	collisionBox.bottom = pos.y - 2;

	if (state == State_Jump)
	{
		gravity += gravityPower;
		pos.y -= jumpPower - gravity;

		if (pos.y > 18)
		{
			state = State_Run;
			gravity = 0;
			pos.y = 18;
		}
	}

	if (state == State_Die)
	{
		gravity += gravityPower;
		pos.y -= jumpPower - gravity;

		if (pos.y > 30) SCENEMANAGER->ChangeScene(NUM_OverScene);
	}

	if (count % 10 == 0)
		isRight = !isRight;
}

void Player::Render()
{
	if (state != State_Die)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
				RENDERMANAGER->Print(pos.x + i, pos.y + j, Color::RED);
		}

		RENDERMANAGER->Print(pos.x + 2, pos.y, Color::BLACK);

		if (isRight) RENDERMANAGER->Print(pos.x, pos.y + 2, Color::BLACK);
		else RENDERMANAGER->Print(pos.x + 2, pos.y + 2, Color::BLACK);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
				RENDERMANAGER->Print(pos.x + i, pos.y - j, Color::RED);
		}

		RENDERMANAGER->Print(pos.x + 2, pos.y, Color::BLACK);

		if (isRight) RENDERMANAGER->Print(pos.x, pos.y - 2, Color::BLACK);
		else RENDERMANAGER->Print(pos.x + 2, pos.y - 2, Color::BLACK);
	}
}

void Player::Die()
{
	state = State_Die;
}

void Player::Jump()
{
	state = State_Jump;
}
