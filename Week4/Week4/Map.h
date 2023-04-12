#pragma once

#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>

using namespace std;

enum MTYPE
{
    START,      //출발
    GOAL,       //도착
    ROAD,       //길
    OBSTACLE,   //장애물
    ROUTE       //경로
};

class Tile {
public:
    int x, y;       //타일의 좌표
    int cost;       //타일 이동 시 드는 비용 코드에서는 0(장애물)과 1(길)만 사용
    bool obstacle;  //장애물 여부
    MTYPE type;     //타일의 상태를 표시

    Tile(int x, int y, int cost, bool obstacle = false);
};

// 타일맵 정보를 저장하는 클래스
class TileMap {
public:
    int width, height;  //맵의 가로세로 크기
    vector<Tile> tiles; //타일 맵정보를 가진 벡터

    TileMap(int width, int height);
        
    void addTile(int x, int y, int cost, bool obstacle = false);
    void PrintMap();
};