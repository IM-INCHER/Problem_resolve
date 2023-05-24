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

struct Node
{
	char* value;
	Node* child = nullptr;
	int depth = 0;
};

Node* CreateNode(const char* value);
void InsertChild(Node* parent, Node* child);
void MakeTree(Node** root, char* str);
void CountingVariable(Node* node, Box* b);
void ParsingString(Node* root1, Node* root2, Box* b);
void PrintNode(Node* root);

bool CompareFromEnd(const char* str1, const char* str2, int len);
char* findCommonSuffix(const char* str1, const char* str2);

int main()
{
	FILE* fp;
	fopen_s(&fp, "a.txt", "r");

	char buffer[1000] = { 0, };
	bool isWirte = false;

	int c;
	int count = 0;

	for (int i = 0; ; i++)
	{
		c = fgetc(fp);

		if (c == EOF) break;

		buffer[i] = (char)c;
	}

	char str1[100] = { 0, };
	char str2[100] = { 0, };
	char* token = NULL;
	char* context = NULL;

	token = strtok_s(buffer, "\n", &context);
	strncpy_s(str1, token, strlen(token));
	token = strtok_s(NULL, "\n", &context);
	strncpy_s(str2, token, strlen(token));

	Node* root1 = nullptr;
	Node* root2 = nullptr;
	Box box;

	MakeTree(&root1, str1);
	MakeTree(&root2, str2);

	CountingVariable(root1, &box);
	ParsingString(root1, root2, &box);

	//PrintNode(root2);

	printf("int(%d): %d\n", box.i, box.iArr);
	printf("char(%d): %c\n", box.c, box.cArr);
	printf("char*(%d): %s\n", box.s, box.sArr);
}

Node* CreateNode(const char* value)
{
	Node* newNode = new Node;
	newNode->value = new char[strlen(value) + 1];
	strcpy_s(newNode->value, strlen(newNode->value) + 1, value);
	newNode->child = nullptr;
	newNode->depth = 0;
	return newNode;
}

void InsertChild(Node* parent, Node* child)
{
	if (parent->child == nullptr)
	{
		child->depth = parent->depth + 1;
		parent->child = child;
	}
}

void MakeTree(Node** root, char* str)
{
	char* token = NULL;
	char* context = NULL;
	Node* currentNode = nullptr;

	token = strtok_s(str, " ", &context);
	while (token != nullptr) {
		Node* newNode = CreateNode(token);
		if (*root == nullptr) {
			*root = newNode;
			currentNode = newNode;
		}
		else
		{
			InsertChild(currentNode, newNode);
			currentNode = newNode;
		}
		token = strtok_s(nullptr, " ", &context);
	}
}

void CountingVariable(Node* node, Box* b)
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
	CountingVariable(node->child, b);
}

void ParsingString(Node* root1, Node* root2, Box* b)
{
	if (root1 == nullptr || root2 == nullptr) return;

	if (strncmp(root1->value, root2->value, strlen(root1->value)) == 0)
	{
		ParsingString(root1->child, root2->child, b);
	}
	else
	{
		switch (root1->value[1])
		{
		case 'd':
			b->iArr = atoi(findCommonSuffix(root1->value, root2->value));
			ParsingString(root1->child, root2->child, b);
			break;
		case 'c':
			b->cArr = root2->value[0];
			ParsingString(root1->child, root2->child, b);
			break;
		case 's':
			if (CompareFromEnd(root1->value, root2->value, 2))
			{
				strcat_s(b->sArr, sizeof(b->sArr), findCommonSuffix(root1->value, root2->value));
				ParsingString(root1->child, root2->child, b);
			}
			else
			{
				strcat_s(b->sArr, sizeof(b->sArr), root2->value);
				strcat_s(b->sArr, sizeof(b->sArr), " ");
				ParsingString(root1, root2->child, b);
			}
			break;
		default:
			break;
		}
	}
}

void PrintNode(Node* root)
{
	if (root == nullptr) return;

	char str[100] = { 0, };

	strcpy_s(str, strlen(root->value) + 1, root->value);
	//printf("%d", sizeof(str));
	printf("%s\n", str);

	PrintNode(root->child);
}

bool CompareFromEnd(const char* str1, const char* str2, int len)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = len1 - 1;
	int j = len2 - 1;

	for (int k = 0; k < len; k++)
	{
		if (str1[i] > str2[j])
			return false;
		else if (str1[i] < str2[j])
			return false;;

		i--;
		j--;
	}

	return true; // 두 문자열이 동일한 경우
}

char* findCommonSuffix(const char* str1, const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int minLen = len1 < len2 ? len1 : len2;  // 두 문자열 중 짧은 길이

	const char* addr1 = str1 + len1 - 1;
	const char* addr2 = str2 + len2 - 1;

	while (addr1 >= str1 && addr2 >= str2 && *addr1 == *addr2) {
		addr1--;
		addr2--;
	}

	int len = strlen(addr2 + 1);
	char str3[100] = "";
	strncat_s(str3, sizeof(str3), str2, strlen(str2) - len);

	return str3;
}


