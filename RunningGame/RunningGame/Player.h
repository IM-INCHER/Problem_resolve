#pragma once
#include "Object.h"

enum PlayerState
{
	State_Run,
	State_Jump,
	State_Die
};

class Player : public Object
{
private:
	Vector3 pos;
	PlayerState state;

	RECT collisionBox;

	float jumpPower;
	float gravity;
	float gravityPower;

	bool isRight;
	int count;

public:
	void Init();
	void Update();
	void Render();

	void Die();
	void Jump();

	RECT GetCollisionBox() { return collisionBox; }
};

