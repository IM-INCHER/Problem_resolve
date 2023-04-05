#include "Tree.h"

Node* BFS::search(int startIdx, int goalIdx)
{
    queue<Node*> frontier;
    vector<bool> visited(tileMap.tiles.size(), false);

    Node* startNode = new Node(startIdx, 0);
    frontier.push(startNode);

    while (!frontier.empty()) {
        Node* current = frontier.front();
        frontier.pop();

        visited[current->tileIdx] = true;

        if (current->tileIdx == goalIdx) {
            return current;
        }

        int cx = tileMap.tiles[current->tileIdx].x;
        int cy = tileMap.tiles[current->tileIdx].y;

        for (int i = 0; i < tileMap.tiles.size(); i++) {
            if (visited[i] || tileMap.tiles[i].obstacle) {
                continue;
            }

            int dx = abs(tileMap.tiles[i].x - cx);
            int dy = abs(tileMap.tiles[i].y - cy);

            if (dx + dy == 1) {
                Node* next = new Node(i, current->depth + 1, current);
                frontier.push(next);
            }
        }
    }

    return nullptr;
}
