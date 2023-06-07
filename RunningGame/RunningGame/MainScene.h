#pragma once
#include <fstream>
#include "Scene.h"

class MainScene : public Scene
{
private:
	int count;
	int select;
	bool isFlicker;

public:
	MainScene();

	void Init();
	void Update();
	void Render();
	void Release();
};

