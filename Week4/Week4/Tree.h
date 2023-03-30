#pragma once

#include "Map.h"

class Node
{
public:
	Tile* _data;
	int _size;
	int _childNum;

	Node** parents_;
	Node** _child;

	bool isVisit;

public:
	Node();
	~Node();

	void SizeUp();
};


class Tree
{
	Node* _rootNode;
	Map* _map;

public:
	Tree(Node* rootNode, Map* map);
	Tree();

	Node* CreateNode(Tile* data);
	Node* InsertNode(Node* node, Tile* data);

	void DistanceBFS(Tile* End);
	void MoveCheck(Node* node);

};


