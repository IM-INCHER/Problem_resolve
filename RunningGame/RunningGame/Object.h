#pragma once
#include "Component.h"

class Object
{
private:
	vector<Component*> components;

public:
	void AddComponent(Component* component);
	void UpdateComponent();

	virtual void Start() {}
	virtual void Update() {}
	virtual void Render() {}
};

