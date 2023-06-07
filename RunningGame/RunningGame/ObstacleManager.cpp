#include "stdafx.h"
#include "ObstacleManager.h"

ObstacleManager::ObstacleManager(int poolSize)
{
    pool.reserve(poolSize);
    usedFlags.reserve(poolSize);
}

ObstacleManager::~ObstacleManager()
{
}

void ObstacleManager::Allocate()
{
    for (int i = 0; i < pool.size(); i++)
    {
        if (!usedFlags[i] && pool[i] != nullptr)
        {
            usedFlags[i] = true;
            pool[i]->Init();

            return;
        }
    }
}

void ObstacleManager::Free(int index)
{
    usedFlags[index] = false;
}

void ObstacleManager::Add(Obstacle* obstacle)
{
    pool.push_back(obstacle);
    usedFlags.push_back(false);
}

bool ObstacleManager::ObstacleCollisionCheck(RECT rc1)
{
    for (int i = 0; i < pool.size(); i++)
    {
        if (usedFlags[i])
        {
            RECT rc2 = pool[i]->GetCollisionBox();

            if (rc1.right < rc2.left || rc1.left > rc2.right) continue;
            if (rc1.top < rc2.bottom || rc1.bottom > rc2.top) continue;

            return true;
        }
    }
   
    return false;
}

void ObstacleManager::SpeedUp()
{
    for (int i = 0; i < pool.size(); i++)
    {
        if (pool[i])
        {
            pool[i]->SetSpeed(pool[i]->GetSpeed() * 1.3f);
        }
    }
}

void ObstacleManager::Init()
{
    for (int i = 0; i < pool.size(); i++)
    {
        usedFlags[i] = false;
        if (pool[i])
        {
            pool[i]->Init();
        }
    }
}

void ObstacleManager::Update()
{
    for (int i = 0; i < pool.size(); i++)
    {
        if (usedFlags[i])
        {
            pool[i]->Update();
            if (pool[i]->FreeCheck()) Free(i);
        }
    }
}

void ObstacleManager::Render()
{
    for (int i = 0; i < pool.size(); i++)
    {
        if (usedFlags[i])
        {
            pool[i]->Render();
        }
    }
}

void ObstacleManager::Release()
{
    for (Obstacle* obstacle : pool)
    {
        delete obstacle;
    }
}
