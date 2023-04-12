#include "Map.h"

//Ÿ�ϸ��� ������
TileMap::TileMap(int width, int height)
{
    this->width = width;
    this->height = height;

    //���� �Է��ϴ� ����
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int cost;
            cin >> cost;

            bool obstacle = (cost == 0);
            addTile(x, y, cost, obstacle);
        }
    }
}

//�ʿ� Ÿ���� �߰��ϴ� �Լ�
void TileMap::addTile(int x, int y, int cost, bool obstacle)
{
    //�Է¹��� ������ �������� ������ �־���
    tiles.emplace_back(x, y, cost, obstacle || cost == 0);
}

//�ܼ�â�� ���� �׷��ִ� �Լ�
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

//Ÿ���� ������
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
