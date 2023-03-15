

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int RomanToint(string str);
int getMatchedValue(char ch);

int main()
{
    string input;

    while (true)
    {
        cout << "로마숫자를 입력해주세요(대문자로 입력해주세요) :";
        cin >> input;

        int num = RomanToint(input);

        if(num < 0)  cout << "잘못된 값이 입력되었습니다." << endl;
        else cout << num << endl;
    }
}

int RomanToint(string str)
{
    int num = 0;

    for (int i = 0; str[i]; i++)
    {
        num += getMatchedValue(str[i]) * ((getMatchedValue(str[i]) < getMatchedValue(str[i + 1])) ? -1 : 1);
    }

    return num;
}

int getMatchedValue(char ch)
{
    char symbols[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
    int values[] = { 1000, 500, 100, 50, 10, 5, 1 };

    for (int i = 0; i < 7; i++)
    {
        if (symbols[i] == ch)
            return values[i];
    }

    return -1;
}
