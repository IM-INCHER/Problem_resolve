#pragma once

class Vector3
{
public:
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
	~Vector3() {};

	Vector3 operator*(float f) { return Vector3(this->x * f, this->y * f, this->z * f); }
};

