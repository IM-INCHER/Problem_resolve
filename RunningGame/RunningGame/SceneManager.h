#pragma once
#include "singletonBase.h"
#include "Scene.h"

#define MAX_SCENES 3

class GameScene;

enum SceneNum
{
	NUM_MainScene,
	NUM_GameScene,
	NUM_OverScene
};

class SceneManager : public singletonBase<SceneManager>
{
private:
	Scene* currentScene;
	Scene* scenes[3];

public:
	void ChangeScene(Scene* newScene);
	void ChangeScene(SceneNum index);
	void AddScene(Scene* newScene);

	void Init();
	void Update();
	void Render();
	void Release();

	bool GetIsGame();
};

