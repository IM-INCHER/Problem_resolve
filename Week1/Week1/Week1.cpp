
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    unsigned short input;
    unsigned short output = 0;

    try
    {
        cout << "수를 입력해주세요 : ";
        cin >> input;
        if (input >= USHRT_MAX)
            throw string("범위를 넘어갑니다");
    }
    catch (string error)
    {
        cout << error << endl;
        return 0;
    }

    while (input != 0) 
    {
        try
        {
            output *= 10;
            if (output >= USHRT_MAX)
                throw string("범위를 넘어갑니다");
        }
        catch (string error)
        {
            cout << error << endl;
            return 0;
        }
        output += input % 10;
        input /= 10;
    }

    cout << output << endl;

    return 0;
}


