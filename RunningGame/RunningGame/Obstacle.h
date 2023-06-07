#pragma once

class Obstacle : public Object
{
protected:
	float speed;

	RECT collisionBox;

public:
	virtual bool FreeCheck() = 0;

	RECT GetCollisionBox() { return collisionBox; }
	void SetSpeed(float sp) { speed = sp; }
	float GetSpeed() { return speed; }
};

class Tree : public Obstacle
{
private:
	Vector3 pos;

public:
	Tree();

	void Init();
	void Update();
	void Render();

	bool FreeCheck();
};

class Rock : public Obstacle
{
private:
	Vector3 pos;

public:
	Rock();

	void Init();
	void Update();
	void Render();

	bool FreeCheck();
};


