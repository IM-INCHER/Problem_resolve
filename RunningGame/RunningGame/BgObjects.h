#pragma once

class BackGround : public Object
{
protected:
	float speed;

public:
	void SpeedUp() { speed *= 1.3f; }

	void SetSpeed(float sp) { speed = sp; }
	float GetSpeed() { return speed; }
};

class Sun : public BackGround
{
private:
	Vector3 pos;

public:
	Sun(float x, float y, float z, float speed);
	~Sun();

	void Init();
	void Update();
	void Render();
};

class Cloud : public BackGround
{
private:
	Vector3 pos;

public:
	Cloud(float x, float y, float z, float speed);

	void Init();
	void Update();
	void Render();
};

class Grand : public BackGround
{
public:
	void Init();
	void Update();
	void Render();
};

class Mountain : public BackGround
{
private:
	Vector3 pos;

public:
	Mountain(float x, float y, float z, float speed);

	void Init();
	void Update();
	void Render();
};