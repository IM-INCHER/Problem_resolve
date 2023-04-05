#pragma once

#include "Map.h"

class Node {
public:
    int tileIdx;
    int depth;
    Node* parent;

    Node(int tileIdx, int depth, Node* parent = nullptr) :
        tileIdx(tileIdx), depth(depth), parent(parent) {}
};

// Ž�� ������ �����ϴ� Ŭ����
class BFS {
public:
    TileMap& tileMap;

    BFS(TileMap& tileMap) :
        tileMap(tileMap) {}

    // BFS Ž�� �Լ�
    Node* search(int startIdx, int goalIdx);
};
