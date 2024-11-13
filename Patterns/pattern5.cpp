/*
*****
****
***
**
*
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i; j <= 5; j++)                    // for (int j = 5; j >= i; j--) [alternative]
        {
            cout <<"*";
        }
        cout << endl;
    }
}