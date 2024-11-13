/*
    A
   ABA
  ABCBA
 ABCDCBA
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        char ch = 'A';
        int spaces = 5 - i;
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }
        int count = 2 * i - 1;
        for (int k = 1; k <= count; k++)
        {
            if (k <= count / 2)
            {
                cout << ch;
                ch++;
            }
            else
            {
                cout << ch;
                ch--;
            }
        }
        cout << endl;
    }
}