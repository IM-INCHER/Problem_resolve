#include <iostream>
#include "Tree.h"

int main()
{
    Node* root = nullptr;
    Tree tree;

    root = tree.InsertNode(root, 1);
    tree.InsertNode(root, 2);
    tree.InsertNode(root, 3);
}
