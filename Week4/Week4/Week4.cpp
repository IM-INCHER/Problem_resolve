#include "Tree.h"

int main()
{
    // 맵 정보 입력
    int width, height;
    cout << "맵의 가로 세로를 입력해 주세요(스페이스바로 구분합니다) : ";
    cin >> width >> height;

    cout << "맵을 그려주세요(1은 길 0은 장애물입니다) : " << endl;
    TileMap tileMap(width, height);

    tileMap.PrintMap();

    // 시작점과 도착점 입력
    int startX, startY, goalX, goalY;
    cout << "시작 좌표를 입력해 주세요(스페이스바로 구분합니다) : ";
    cin >> startX >> startY;
    cout << "도착 좌표를 입력해 주세요(스페이스바로 구분합니다) : ";
    cin >> goalX >> goalY;

    int startIdx = startY * width + startX;
    int goalIdx = goalY * width + goalX;

    // BFS 탐색
    BFS bfs(tileMap);
    Node* result = bfs.search(startIdx, goalIdx);

    // 결과 출력
    if (result == nullptr) {
        cout << "경로를 찾을 수 없습니다." << endl;
    }
    else {
        //최단 경로를 저장하는 벡터 선언
        vector<Node*> path;
        Node* current = result;
        while (current != nullptr) {
            //트리의 root에 도달할때까지 반복
            path.push_back(current);
            current = current->parent;
        }

        cout << "최단 거리: " << result->depth << endl;

        //경로에 해당하는 타일의 상태를 변경해주는 코드
        for (int i = path.size() - 1; i >= 0; i--) {
            if (i == path.size() - 1)
                tileMap.tiles[path[i]->tileIdx].type = START;
            else if(i == 0)
                tileMap.tiles[path[i]->tileIdx].type = GOAL;
            else
                tileMap.tiles[path[i]->tileIdx].type = ROUTE;
        }
        tileMap.PrintMap();
    }

    return 0;
}
