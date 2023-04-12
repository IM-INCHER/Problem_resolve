#pragma once

#include "Map.h"

class Node {
public:
    int tileIdx;    //Ÿ�ϸ��� �ε��� ��ȣ�� ����
    int depth;      //���� ���� �ɼ��� �Ÿ����� ���
    Node* parent;   //�θ����� �ּ�

    Node(int tileIdx, int depth, Node* parent = nullptr) :
        tileIdx(tileIdx), depth(depth), parent(parent) {}
};

// Ž�� ������ �����ϴ� Ŭ����
class BFS {
public:
    TileMap& tileMap;   //Ÿ�ϸ��� �ּҰ��� ����

    BFS(TileMap& tileMap) :
        tileMap(tileMap) {}

    // BFS Ž�� �Լ�
    Node* search(int startIdx, int goalIdx);
};
