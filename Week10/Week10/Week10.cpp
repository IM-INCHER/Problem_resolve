#define BUFMAX 1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Box
{
    int i = 0;
    int c = 0;
    int s = 0;

    int iArr = 0;
    char cArr = 0;
    char sArr[100] = "";
};

struct Node {
    char* value;
    Node* child = nullptr;
    Node* sibling = nullptr;
};

Node* createNode(const char* value);
void insertChild(Node* parent, Node* child);
void parseString(Node* node, Box* b);
void parsingString(Node* root, char* value, Box* b);
void destroyTree(Node* node);

int main()
{
    FILE* fp;
    fopen_s(&fp, "a.txt", "r");

    Box box;

    char buffer[BUFMAX] = { 0 };

    if (fgets(buffer, BUFMAX, fp) == nullptr)
    {
        printf("문장을 읽어오지 못했습니다.\n");
        return 1;
    }

    Node* root = nullptr;
    Node* currentNode = nullptr;

    char* context = nullptr;

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

    parseString(root, &box);

    //box.iArr = (int*)malloc(sizeof(int) * box.i);
    //box.cArr = (char*)malloc(sizeof(char) * box.c);
    //box.sArr = (char**)malloc(sizeof(char*) * box.s);

    if (fgets(buffer, BUFMAX, fp) == nullptr)
    {
        printf("문장을 읽어오지 못했습니다.\n");
        return 1;
    }

    token = NULL;
    context = NULL;

    token = strtok_s(buffer, " ", &context);
    while (token != nullptr) {
        parsingString(root ,token, &box);

        token = strtok_s(nullptr, " ", &context);
    }

    printf("int(%d): %d\n", box.i, box.iArr);
    printf("char(%d): %c\n", box.c, box.cArr);
    printf("char*(%d): %s\n", box.s, box.sArr);

    destroyTree(root);

    fclose(fp);

    /*free(box.iArr);
    free(box.cArr);
    free(box.sArr);*/

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
        /*Node* sibling = parent->child;
        while (sibling->sibling != nullptr) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;*/
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
        char str[3] = { value[0] , value[1] };
        Node* newNode = createNode(str);
        node->sibling = newNode;

        char* str2 = value + 2;
        newNode = createNode(str2);
        node->sibling->child = newNode;
    }

    parseString(node->child, b);
    //parseString(node->sibling, b);
}

void parsingString(Node* node, char* value, Box* b)
{
    if (node->child == NULL) return;
    if (node->sibling == NULL)
    {
        parsingString(node->child, value, b);
        return;
    }

    char* str = strstr(value, node->sibling->child->value);

    if (str == NULL)
    {
        parsingString(node->child, value, b);
        return;
    }

    int len = strlen(str);
    char str2[100] = "";
    strncat_s(str2, sizeof(str2), value, strlen(value) - len);

    switch (node->sibling->value[1])
    {
    case 'd':
        b->iArr = atoi(str2);
        break;
    case 'c':
        b->cArr = str2[0];
        break;
    case 's':
        //b->sArr = str2;

        strncat_s(b->sArr, sizeof(b->sArr), str2, strlen(str2));
        break;
    default:
        break;
    }
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