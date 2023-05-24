#include "stdafx.h"
#include "Component.h"

void Transform::translate(Vector3 v)
{
	position.x += v.x;
	position.y += v.y;
	position.z += v.z;
}
