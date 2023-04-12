#include "Tree.h"

Node* BFS::search(int startIdx, int goalIdx)
{
    //BFS탐색에 사용할 큐와 방문 여부를 저장할 벡터 선언
    queue<Node*> frontier;
    vector<bool> visited(tileMap.tiles.size(), false);

    //시작 노드를 생성하고 큐에 추가
    Node* startNode = new Node(startIdx, 0);
    frontier.push(startNode);

    //BFS탐색 시작
    while (!frontier.empty()) {
        //큐에서 타일을 하나 꺼내 현재 노드로 설정
        Node* current = frontier.front();
        frontier.pop();

        //현재 노드가 방문되었음을 표시
        visited[current->tileIdx] = true;

        //도착 지점에 도달했다면, 현재 노드를 반환
        if (current->tileIdx == goalIdx) {
            return current;
        }

        //현재 타일의 좌표를 구함
        int cx = tileMap.tiles[current->tileIdx].x;
        int cy = tileMap.tiles[current->tileIdx].y;

        //현재 타일과 이동 가능한 모든 타일을 비교
        for (int i = 0; i < tileMap.tiles.size(); i++) 
        {
            //이미 방문했거나 장애물일 경우 무시
            if (visited[i] || tileMap.tiles[i].obstacle) {
                continue;
            }
            
            //이동 가능한 타일은 현재 타일의 상하좌우에 위치한 타일
            int dx = abs(tileMap.tiles[i].x - cx);
            int dy = abs(tileMap.tiles[i].y - cy);

            //상하좌우에 인접한 타일인 경우, 새로운 노드를 생성하여 큐에 추가
            if (dx + dy == 1) {
                Node* next = new Node(i, current->depth + 1, current);
                frontier.push(next);
            }
        }
    }

    return nullptr;
}
