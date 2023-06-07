#pragma once
#include "MainScene.h"
#include "GameScene.h"
#include "OverScene.h"

class mainGame
{
private:
	bool _isGameRunning;

public:
	mainGame();
	~mainGame();

	void Run();
	void Stop();

	void Init();
	void Update();
	void Render();
	void Release();

	
};

