#include "Tree.h"

Tree::Tree(Node* rootNode)
{
	_rootNode = rootNode;

}

Tree::Tree()
{
}

Node* Tree::CreateNode(int data)
{
	Node* node = new Node();
	node->_data = data;
	node->isVisit = false;

	return node;
}

Node* Tree::InsertNode(Node* node, int data)
{
	if (node == nullptr)
		return CreateNode(data);

	if (node->_childNum == node->_size) node->SizeUp();

	node->_child[node->_childNum] = InsertNode(node->_child[node->_childNum], data);
	node->_childNum++;

	/*if (data < node->_data)
	{
		node->_child[0] = InsertNode(node->_child[0], data);
	}
	else if (data > node->_data)
	{
		node->_child[1] = InsertNode(node->_child[1], data);
	}*/

	return node;
}

Node::Node()
{
	_childNum = 0;
	_size = 10;
	_child = new Node * [_size];

	for (int i = 0; i < _size; i++)
	{
		_child[i] = nullptr;
	}
}

Node::~Node()
{
	delete[] _child;
}

void Node::SizeUp()
{
	int newSize = _size + 5;
	Node** newArr = new Node * [newSize];

	for (int i = 0; i < _size; i++)
	{
		newArr[i] = _child[i];
	}

	delete[] _child;

	_child = newArr;
	_size = newSize;
}
