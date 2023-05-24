#include "stdafx.h"
#include "Object.h"

void Object::AddComponent(Component* component)
{
	components.push_back(component);
}

void Object::UpdateComponent()
{
	for (Component* component : components) component->Update();
}
