#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

void mainGame::Run()
{
	_isGameRunning = true;
	Init();

	while (_isGameRunning)
	{
		Update();
		Render();

		if (SCENEMANAGER->GetIsGame()) break;
	}

	Release();
}

void mainGame::Stop()
{
	_isGameRunning = false;
}

void mainGame::Init()
{
	RENDERMANAGER->Init();

	SCENEMANAGER->AddScene(new MainScene);
	SCENEMANAGER->AddScene(new GameScene);
	SCENEMANAGER->AddScene(new OverScene);

	SCENEMANAGER->ChangeScene(NUM_MainScene);
}

void mainGame::Update()
{
	SCENEMANAGER->Update();
}

void mainGame::Render()
{
	SCENEMANAGER->Render();
	RENDERMANAGER->Render();
}

void mainGame::Release()
{
	SCENEMANAGER->Release();
	SCENEMANAGER->releaseSingleton();
	RENDERMANAGER->Release();
	RENDERMANAGER->releaseSingleton();
}

