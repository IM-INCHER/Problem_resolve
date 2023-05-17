#define BUFMAX 1000

#include <stdio.h>
#include <string>

using namespace std;

struct Box
{
    int i = 0;
    int c = 0;
    int s = 0;

    int iArr = 0;
    char cArr = 0;
    char* sArr = NULL;
};

struct Node {
    char* value;
    Node* child;
    Node* sibling;
};

Node* createNode(const char* value);
void insertChild(Node* parent, Node* child); 
void parseString(Node* node, Box* b);
void destroyTree(Node* node); 

int main() 
{
    FILE* fp;
    fopen_s(&fp, "a.txt", "r");

    Box box;

    char buffer[BUFMAX] = { 0, };

    fread(buffer, BUFMAX, 1, fp);

    printf("%s\n", buffer);

    Node* root = nullptr;
    Node* currentNode = nullptr;

    char* context = NULL;

    char* token = strtok_s(buffer, " ", &context);
    while (token != nullptr) {
        Node* newNode = createNode(token);
        if (root == nullptr) {
            root = newNode;
            currentNode = newNode;
        }
        else {
            insertChild(currentNode, newNode);
            currentNode = newNode;
        }
        token = strtok_s(nullptr, " ", &context);
    }

    parseString(root,&box);

    printf("int = %d\nchar = %d\nchar* = %d\n", box.i, box.c, box.s);

    destroyTree(root);

    return 0;
}

Node* createNode(const char* value)
{
    Node* newNode = new Node;
    newNode->value = new char[strlen(value) + 1];
    strcpy_s(newNode->value, strlen(newNode->value) + 1, value);
    newNode->child = nullptr;
    newNode->sibling = nullptr;
    return newNode;
}

void insertChild(Node* parent, Node* child)
{
    if (parent->child == nullptr) {
        parent->child = child;
    }
    else {
        Node* sibling = parent->child;
        while (sibling->sibling != nullptr) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;
    }
}

void parseString(Node* node, Box* b)
{
    if (node == nullptr) {
        return;
    }

    char* value = node->value;
    if (value[0] == '%' && value[1] != '\0') 
    {
        char specifier = value[1];
        switch (specifier) {
        case 's':
            b->s++;
            break;
        case 'd':
            b->i++;
            break;
        case 'c':
            b->c++;
            break;
        default:
            printf("Unknown specifier: %c", specifier);
            break;
        }
    }

    parseString(node->child, b);
    parseString(node->sibling, b);
}

void destroyTree(Node* node)
{
    if (node == nullptr) {
        return;
    }

    destroyTree(node->child);
    destroyTree(node->sibling);
    //delete[] node->value;
    delete node;
}
