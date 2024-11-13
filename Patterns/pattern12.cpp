/*
1        1
12      21
123    321
1234  4321
1234554321
*/

#include <iostream>
using namespace std;

int main()
{
    int spaces = 2 * (5 - 1);
    // left side numbers
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // for spaces
        for (int i = 1; i <= spaces; i++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        spaces = spaces - 2;
    }
}