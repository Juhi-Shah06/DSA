/*
 *        *
 **      **
 ***    ***
 ****  ****
 **********
 ****  ****
 ***    ***
 **      **
 *        *
 */

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        int spaces = 2 * 5 - 2 * i;
        for (int k = 1; k <= spaces; k++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 5; i >=1; i--)
    {
        for (int j = i-1; j > 0; j--)
        {
            cout << "*";
        }
        int spaces = 2 * 5 - 2 * (i-1);
        for (int k = 1; k <= spaces; k++)
        {
            cout << " ";
        }
        for (int j = 1; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
