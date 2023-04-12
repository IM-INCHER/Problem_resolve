#include "Map.h"

//타일맵의 생성자
TileMap::TileMap(int width, int height)
{
    this->width = width;
    this->height = height;

    //맵을 입력하는 구간
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int cost;
            cin >> cost;

            bool obstacle = (cost == 0);
            addTile(x, y, cost, obstacle);
        }
    }
}

//맵에 타일을 추가하는 함수
void TileMap::addTile(int x, int y, int cost, bool obstacle)
{
    //입력받은 정보를 기준으로 벡터의 넣어줌
    tiles.emplace_back(x, y, cost, obstacle || cost == 0);
}

//콘솔창에 맵을 그려주는 함수
void TileMap::PrintMap()
{
    for (int i = 0; i < tiles.size(); i++)
    {
        switch (tiles[i].type)
        {
        case START:
            cout << "S\t";
            break;
        case GOAL:
            cout << "G\t";
            break;
        case OBSTACLE:
            cout << "X\t";
            break;
        case ROAD:
            cout << ".\t";
            break;
        case ROUTE:
            cout << "O\t";
            break;
        default:
            break;
        }

        if (i % width == width - 1)
            cout << endl << endl;
    }
}

//타일의 생성자
Tile::Tile(int x, int y, int cost, bool obstacle)
{
    this->x = x;
    this->y = y;
    this->cost = cost;
    this->obstacle = obstacle;
    
    switch (cost)
    {
    case 0:
        this->type = OBSTACLE;
        break;
    case 1:
        this->type = ROAD;
    default:
        break;
    }
}
