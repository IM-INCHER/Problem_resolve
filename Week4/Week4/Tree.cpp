#include "Tree.h"

Node* BFS::search(int startIdx, int goalIdx)
{
    //BFSŽ���� ����� ť�� �湮 ���θ� ������ ���� ����
    queue<Node*> frontier;
    vector<bool> visited(tileMap.tiles.size(), false);

    //���� ��带 �����ϰ� ť�� �߰�
    Node* startNode = new Node(startIdx, 0);
    frontier.push(startNode);

    //BFSŽ�� ����
    while (!frontier.empty()) {
        //ť���� Ÿ���� �ϳ� ���� ���� ���� ����
        Node* current = frontier.front();
        frontier.pop();

        //���� ��尡 �湮�Ǿ����� ǥ��
        visited[current->tileIdx] = true;

        //���� ������ �����ߴٸ�, ���� ��带 ��ȯ
        if (current->tileIdx == goalIdx) {
            return current;
        }

        //���� Ÿ���� ��ǥ�� ����
        int cx = tileMap.tiles[current->tileIdx].x;
        int cy = tileMap.tiles[current->tileIdx].y;

        //���� Ÿ�ϰ� �̵� ������ ��� Ÿ���� ��
        for (int i = 0; i < tileMap.tiles.size(); i++) 
        {
            //�̹� �湮�߰ų� ��ֹ��� ��� ����
            if (visited[i] || tileMap.tiles[i].obstacle) {
                continue;
            }
            
            //�̵� ������ Ÿ���� ���� Ÿ���� �����¿쿡 ��ġ�� Ÿ��
            int dx = abs(tileMap.tiles[i].x - cx);
            int dy = abs(tileMap.tiles[i].y - cy);

            //�����¿쿡 ������ Ÿ���� ���, ���ο� ��带 �����Ͽ� ť�� �߰�
            if (dx + dy == 1) {
                Node* next = new Node(i, current->depth + 1, current);
                frontier.push(next);
            }
        }
    }

    return nullptr;
}
