#pragma once

#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>

using namespace std;

enum MTYPE
{
    START,
    GOAL,
    ROAD,
    OBSTACLE,
    ROUTE
};

class Tile {
public:
    int x, y;
    int cost;
    bool obstacle;
    MTYPE type;

    Tile(int x, int y, int cost, bool obstacle = false);
};

// 타일맵 정보를 저장하는 클래스
class TileMap {
public:
    int width, height;
    vector<Tile> tiles;

    TileMap(int width, int height);
        

    void addTile(int x, int y, int cost, bool obstacle = false) {
        tiles.emplace_back(x, y, cost, obstacle || cost == 0);
    }
    void PrintMap();
};