#pragma once
class Tree
{
	Node* _rootNode;

public:
	Tree(Node* rootNode);
	Tree();

	Node* CreateNode(int data);
	Node* InsertNode(Node* node, int data);

};

class Node
{
public:
	int _data;
	int _size;
	int _childNum;

	Node** _child;

	bool isVisit;

public:
	Node();
	~Node();

	void SizeUp();
};

