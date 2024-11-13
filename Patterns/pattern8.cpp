/*
*********
 *******
  *****
   ***
    *
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++) // i = rows
    {
        int k = i;                              // k = spaces
        for (int j = 0; j < 2 * 5 - i - 1; j++) // j = columns 
            if (k)
            {
                cout << " ";
                k--;
            }
            else
            {
                cout << "*";
            }

        cout << endl;
    }
}