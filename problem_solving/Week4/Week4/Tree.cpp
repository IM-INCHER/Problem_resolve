#include "Tree.h"

Tree::Tree(Node* rootNode, Map* map)
{
	_rootNode = rootNode;
	_map = map;

}

Tree::Tree()
{
}

Node* Tree::CreateNode(Tile* data)
{
	Node* node = new Node();
	node->_data = data;
	node->isVisit = false;

	return node;
}

Node* Tree::InsertNode(Node* node, Tile* data)
{
	if (node == nullptr)
		return CreateNode(data);

	if (node->_childNum == node->_size) node->SizeUp();

	node->_child[node->_childNum] = InsertNode(node->_child[node->_childNum], data);
	node->_child[node->_childNum]->parents_ = &node;
	node->_childNum++;

	return node;
}

void Tree::DistanceBFS(Tile* End)
{
	MoveCheck(_rootNode);
	for (int i = 0; i < _rootNode->_childNum; i++)
	{
		MoveCheck(_rootNode->_child[i]);
	}
}

void Tree::MoveCheck(Node* node)
{
	if (node->_data->index % MAP_MAX_X != MAP_MAX_X - 1)
		InsertNode(node, &_map->SearchTile(node->_data->index + 1));

	if (node->_data->index % MAP_MAX_X != 0)
		InsertNode(node, &_map->SearchTile(node->_data->index - 1));

	if (node->_data->index + MAP_MAX_X < MAP_MAX_X * MAP_MAX_Y)
		InsertNode(node, &_map->SearchTile(node->_data->index + MAP_MAX_X));

	if (node->_data->index - MAP_MAX_X > 0)
		InsertNode(node, &_map->SearchTile(node->_data->index - MAP_MAX_X));
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
