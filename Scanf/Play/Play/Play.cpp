#define MAX 1000

#include <iostream>
#include <string.h>

using namespace std;

struct charBox
{
    int iarr = 0;
    char carr = 0;
    char* sarr = 0;

    int i = 0;
    int c = 0;
    int s = 0;
};

//typedef struct Node 
//{
//    char* value;
//    struct Node* child;
//} Node;

int parsing(char* str, charBox* CB);

int main()
{
    FILE* fp = NULL;
    int ch;
    int index = 0;

    charBox cb;

    char buffer[MAX] = { 0, };

    /*fopen_s(&fp, "a.txt", "rt");
    if (fp == NULL)
    {
        cout << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    fread_s(buffer, MAX, MAX, 1, fp);*/

    //for (int i = 0; i < strlen(buffer); i++)
    //{
    //    printf("%c", buffer[i]);  // 개별 요소 출력
    //}
    //cout << endl;

    //fclose(fp);

    //parsing(buffer, &cb);

    printf("int의 갯수 = %d\nchar의 갯수 = %d\n문자열의 갯수 = %d\n", cb.i, cb.c, cb.s);
}

int parsing(char* str, charBox* CB)
{
    char* token = NULL;
    char* context = NULL;

    token = strtok_s(str, "\n", &context);

    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '%')
        {
            i++;
            switch (token[i])
            {
            case 'd':
                CB->i++;
                break;
            case 'c':
                CB->c++;
                break;
            case 's':
                CB->s++;
                break;
            }
        }
    }

    return 0;
}
