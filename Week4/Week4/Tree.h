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

// 탐색 정보를 저장하는 클래스
class BFS {
public:
    TileMap& tileMap;

    BFS(TileMap& tileMap) :
        tileMap(tileMap) {}

    // BFS 탐색 함수
    Node* search(int startIdx, int goalIdx);
};
