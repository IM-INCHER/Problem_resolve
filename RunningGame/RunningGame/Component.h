#pragma once

class Component
{
public:
	virtual void Update() {}
};

class Transform : public Component
{
private:
	Vector3 position;
	Vector3 scale;
	Vector3 rotate;

public:
	void Update() override;
	void translate(Vector3 v);
};

class Renderer : public Component
{
public:
	void Update() override;
};