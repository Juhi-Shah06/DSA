/*
ABCDE
ABCD
ABC
AB
A
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i = 4; i >= 0; i--)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}