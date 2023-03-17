

#include <iostream>
#include <string>
#include <stdexcept>
#include <conio.h>
#include <vector>

using namespace std;

string intToRoman(int num);

int main()
{
    int num;
    bool isEsc = false;
    vector<char> input;

    while (true)
    {
        try
        {
            cout << "1~3999 사이의 값을 입력해 주세요 :";
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

            num = stoi(str);

            if (num > 3999 || num <= 0)
                throw string("범위를 넘어갑니다.");
        }
        catch (string error)
        {
            num = 0;
            cout << error << endl;
            continue;
        }
        catch (const invalid_argument& e) {
            cout << "정수형이 아닙니다." << std::endl;
            continue;
        }


        string roman = intToRoman(num);
        cout << roman << endl;
    }
}

string intToRoman(int num)
{
    string roman = "";

    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            roman += symbols[i];
            num -= values[i];
        }
    }

    return roman;
}

//1~3999 받으면 함수로 로마 숫자 변환하기