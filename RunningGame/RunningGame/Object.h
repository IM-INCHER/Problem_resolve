#pragma once
#include <vector>

class Object
{
private:
	Vector3 pos;

public:
	virtual void Init() {}
	virtual void Update() {}
	virtual void Render() {}

	float GetPosZ() { return pos.z; }
};

