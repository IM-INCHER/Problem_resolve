

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

int RomanToint(string str);
int getMatchedValue(char ch);

int main()
{
    vector<char> input;
    //string input;
    bool isEsc = false;

    while (true)
    {
        cout << "로마숫자를 입력해주세요(대문자로 입력해주세요) :";

        while (true)
        {
            if (_kbhit())
            {
                char ch = _getch();

                if (ch == 27)
                {
                    isEsc = true;
                    break;
                }
                else if (ch == '\b')
                {
                    if (input.size() != 0)
                    {
                        input.pop_back();
                        cout << '\b' << " " << "\b";
                    }
                }
                else if (ch == '\r')
                {
                    cout << endl;
                    break;
                }
                else
                {
                    input.push_back(ch);
                    cout << input.back();
                }
            }
        }

        if (isEsc) break;

        string str(input.begin(), input.end());
        input.clear();

        int num = RomanToint(str);

        if(num < 0)  cout << "잘못된 값이 입력되었습니다." << endl;
        else cout << num << endl;
    }
}

int RomanToint(string str)
{
    int num = 0;
    int count = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == str[i + 1]) count++;
        else if (str[i] != str[i + 1]) count = 0;

        if (i != 0 && getMatchedValue(str[i - 1]) < getMatchedValue(str[i]))
        {
            if (getMatchedValue(str[i]) / getMatchedValue(str[i - 1]) != 5 && getMatchedValue(str[i]) / getMatchedValue(str[i - 1]) != 10)
            {
                return -1;
            }
        }

        if (getMatchedValue(str[i]) < getMatchedValue(str[i + 2]) || getMatchedValue(str[i]) < getMatchedValue(str[i + 3])) return -1;

        if (count >= 3) return -1;

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
