#pragma once
#include "Obstacle.h"

class ObstacleManager
{
private:
    vector<Obstacle*> pool;
    vector<bool> usedFlags;

public:
    ObstacleManager(int poolSize);
    ~ObstacleManager();

    void Allocate();
    void Free(int index);
    void Add(Obstacle* obstacle);
    bool ObstacleCollisionCheck(RECT rc);

    void SpeedUp();

    void Init();
    void Update();
    void Render();
    void Release();
};

