/*Write a program to print numbers from 1 to n by backtracking by using recursion*/
// Time complexity: O(N)
// Space complexity: O(N)

#include <iostream>
using namespace std;

void number(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    else
    {
        number(i - 1, n);
        cout << i << " ";
    }
}

int main()
{
    int n;
    cout << "Enter value for n: ";
    cin >> n;
    number(n, n);
}
