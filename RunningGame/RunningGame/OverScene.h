#pragma once
#include "stdafx.h"
#include "Scene.h"

#include <fstream>
#include <algorithm>


class OverScene : public Scene
{
private:
	int count;
	int select;
	bool isFlicker;
	vector<int> rankings;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	void LoadRankingFromFile();
	void SaveRankingToFile();
};

