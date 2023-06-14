#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
	OM.Add(new Tree());
	OM.Add(new Rock());
	OM.Add(new Tree());
	OM.Add(new Rock());
	OM.Add(new Tree());
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	map.Init();
	player.Init();
	OM.Init();

	count = 0;
	score = 0;
	random = rand() % SPAWNCOUNT + 20;
	isPlayerDead = false;
	isPause = false;

	spawnTime = 0;
}

void GameScene::Update()
{
	if (isPause == false)
	{
		if (isPlayerDead == false)
		{
			count++;
			score++;

			map.Update();
			OM.Update();

			if (score % 200 == 0)
			{
				map.SpeedUp();
				OM.SpeedUp();

				if(spawnTime < 10) spawnTime++;
			}

			if (count == random)
			{
				count = 0;
				random = rand() % SPAWNCOUNT + 20 - spawnTime;
				OM.Allocate();
			}

			if (OM.ObstacleCollisionCheck(player.GetCollisionBox()))
			{
				player.Die();
				isPlayerDead = true;
			}

			if (_kbhit())
			{
				char input = _getch();

				if (input == 32) player.Jump();
				else if(input == 27) isPause = !isPause;
			}
		}
		

		player.Update();
	}
	else
	{
		if (_kbhit())
		{
			char input = _getch();
			if (input == 27) isPause = !isPause;
		}
	}
}

void GameScene::Render()
{
	map.Render();
	OM.Render();
	player.Render();

	string str = to_string(score);
	RENDERMANAGER->Print(100, 1, L"SCORE :", BLACK, Color::LIGHTCYAN);
	RENDERMANAGER->Print(108, 1, str.c_str(), BLACK, Color::LIGHTCYAN);

	RENDERMANAGER->Print(108, 28, "PAUSE ESC", BLACK, Color::BROWN);

	if (isPause)
	{
		RENDERMANAGER->Print(58, 13, BLACK);
		RENDERMANAGER->Print(59, 13, BLACK);
		RENDERMANAGER->Print(58, 14, BLACK);
		RENDERMANAGER->Print(59, 14, BLACK);
		RENDERMANAGER->Print(58, 15, BLACK);
		RENDERMANAGER->Print(59, 15, BLACK);

		RENDERMANAGER->Print(61, 13, BLACK);
		RENDERMANAGER->Print(62, 13, BLACK);
		RENDERMANAGER->Print(61, 14, BLACK);
		RENDERMANAGER->Print(62, 14, BLACK);
		RENDERMANAGER->Print(61, 15, BLACK);
		RENDERMANAGER->Print(62, 15, BLACK);
	}
}

void GameScene::Release()
{
	map.Release();
	OM.Release();
}


