/*
1
01
101
0101
10101
*/

#include <iostream>
using namespace std;

int main()
{
    int start;
    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}