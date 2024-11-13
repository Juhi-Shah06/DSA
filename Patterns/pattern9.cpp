/*
    *
   ***
  *****
 *******
 *******
  *****
   ***
    *
*/

#include <iostream>
using namespace std;

int main()
{
    // upper half
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // lower half
    for (int i = 5 - 1; i >= 1; i--)
    {
        for (int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
};