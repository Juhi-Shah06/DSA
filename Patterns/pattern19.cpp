/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/

#include <iostream>
using namespace std;

int main()
{
    int j;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            cout << "*";
        }
        for (int k = 0; k <= 2 * i; k++)
        {
            cout << " ";
        }
        for (int j = i; j <= 5; j++)
        {
            cout << "*";
        }
        
    }
}