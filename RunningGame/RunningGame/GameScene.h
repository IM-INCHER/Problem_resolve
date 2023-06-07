#pragma once

#include "Map.h"
#include "Player.h"
#include "ObstacleManager.h"
#include "Scene.h"

#define SPAWNCOUNT 80


class GameScene : public Scene
{
private:
	Map map;
	Player player;
	ObstacleManager OM = { 10 };

	int count = 0;
	int random = 0;

	int spawnTime;

	bool isPlayerDead;
	bool isPause;
	
public:
	GameScene();
	~GameScene();

	void Init();
	void Update();
	void Render();
	void Release();
};

