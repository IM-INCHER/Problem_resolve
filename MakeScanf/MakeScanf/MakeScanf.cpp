//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void MyScanf(const char* format, void* a1, void* a2, void* a3, void* a4);

int main()
{
    int a = 0;
    float b = 0;
    char c = 0;
    char* d = NULL;

    MyScanf("%d\t%f\t%c\t%s", &a, &b, &c, &d);

    printf("%d, %f, %c, %s\n", a, b, c, d);
    return 0;
}

void MyScanf(const char* format, void* a1, void* a2, void* a3, void* a4)
{
    char input[1024];  
    char* token;      
    int index = 0;

    char* context = NULL;

    void* var[4] = { a1, a2, a3, a4 };

    // 키보드로부터 입력받은 문자열을 버퍼에 저장
    gets_s(input, sizeof(input));

    // 입력받은 문자열을 지정된 형식에 따라 값을 저장
    token = strtok_s(input, " \t", &context);
    while (*format) {
        if (*format == '%') {
            switch (*(++format)) {
            case 'd':
                if (token != NULL) {
                    *(int*)var[index] = atoi(token);
                    index++;
                    token = strtok_s(NULL, " \t", &context);
                }
                break;
            case 'f':
                if (token != NULL) {
                    *(float*)var[index] = atof(token);
                    index++;
                    token = strtok_s(NULL, " \t", &context);
                }
                break;
            case 'c':
                if (token != NULL) {
                    *(char*)var[index] = token[0];
                    index++;
                    token = strtok_s(NULL, " \t", &context);
                }
                break;
            case 's':
                if (token != NULL) {
                    *(char**)var[index] = token;
                    index++;
                    token = strtok_s(NULL, " \t", &context);
                }
                break;
            default:
                break;
            }
        }
        format++;
    }

}


