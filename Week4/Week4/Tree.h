#pragma once

#include "Map.h"

class Node {
public:
    int tileIdx;    //타일맵의 인덱스 번호를 저장
    int depth;      //깊이 증가 될수록 거리계산시 사용
    Node* parent;   //부모노드의 주소

    Node(int tileIdx, int depth, Node* parent = nullptr) :
        tileIdx(tileIdx), depth(depth), parent(parent) {}
};

// 탐색 정보를 저장하는 클래스
class BFS {
public:
    TileMap& tileMap;   //타일맵의 주소값을 지님

    BFS(TileMap& tileMap) :
        tileMap(tileMap) {}

    // BFS 탐색 함수
    Node* search(int startIdx, int goalIdx);
};
