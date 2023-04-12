#pragma once

#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>

using namespace std;

enum MTYPE
{
    START,      //���
    GOAL,       //����
    ROAD,       //��
    OBSTACLE,   //��ֹ�
    ROUTE       //���
};

class Tile {
public:
    int x, y;       //Ÿ���� ��ǥ
    int cost;       //Ÿ�� �̵� �� ��� ��� �ڵ忡���� 0(��ֹ�)�� 1(��)�� ���
    bool obstacle;  //��ֹ� ����
    MTYPE type;     //Ÿ���� ���¸� ǥ��

    Tile(int x, int y, int cost, bool obstacle = false);
};

// Ÿ�ϸ� ������ �����ϴ� Ŭ����
class TileMap {
public:
    int width, height;  //���� ���μ��� ũ��
    vector<Tile> tiles; //Ÿ�� �������� ���� ����

    TileMap(int width, int height);
        
    void addTile(int x, int y, int cost, bool obstacle = false);
    void PrintMap();
};