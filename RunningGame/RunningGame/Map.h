#pragma once
#include "BgObjects.h"

class Map
{
private:
	Grand grand;
	vector<BackGround*> bgObjs;

public:
	Map();

	void SpeedUp();

	void Init();
	void Update();
	void Render();
	void Release();
};

