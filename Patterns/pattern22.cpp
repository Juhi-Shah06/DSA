/*
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/

#include <iostream>
using namespace std;

int main()
{
    int j;
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (i == 1 || i == 7 || j == 1 || j == 7)
            {
                cout << "4";
            }
            else if (i == 2 || i == 6 || j == 2 || j == 6)
            {
                cout << "3";
            }
            else if (i == 3 || i == 5 || j == 3 || j == 5)
            {
                cout << "2";
            }
            else
            {
                cout << "1";
            }
        }
        cout << endl;
    }
}