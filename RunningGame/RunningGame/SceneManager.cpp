#include "stdafx.h"
#include "SceneManager.h"

void SceneManager::ChangeScene(Scene* newScene)
{
    currentScene = newScene;
    currentScene->Init();
}

void SceneManager::ChangeScene(SceneNum index)
{
    if (index >= 0 && index < MAX_SCENES)
    {
        currentScene = scenes[index];
        currentScene->Init();
    }
}

void SceneManager::AddScene(Scene* newScene)
{
    for (int i = 0; i < MAX_SCENES; ++i)
    {
        if (scenes[i] == nullptr)
        {
            scenes[i] = newScene;
            return;
        }
    }
}

void SceneManager::Init()
{
    for (int i = 0; i < MAX_SCENES; ++i)
    {
        scenes[i] = nullptr;
    }
}

void SceneManager::Update()
{
    if (currentScene)
        currentScene->Update();
}

void SceneManager::Render()
{
    if (currentScene)
        currentScene->Render();
}

void SceneManager::Release()
{
    for (int i = 0; i < MAX_SCENES; ++i)
    {
        if (scenes[i])
        {
            delete scenes[i];
            scenes[i] = nullptr;
        }
    }
}

bool SceneManager::GetIsGame()
{
    return currentScene->GetIsGame();
}