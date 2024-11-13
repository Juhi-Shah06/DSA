/*
    A
   BBB
  CCCC
 DDDDD
EEEEEE
*/

#include <iostream>
using namespace std;

int main()
{
    char ch = 'A';
    for (int i = 1; i <= 5; i++) // i = rows
    {
        int k = 5 - i; // k = spaces
        for (int j = 0; j < k; j++)
        {
            cout << " ";
        }
        for (int m = 0; m < 2 * i - 1; m++) // m = columns for printing the stars
            cout <<ch;
            ch++;
            cout << endl;
    }
    
}