/*Write a program to print numbers from n to 1 by using recursion*/
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
        cout << i << " ";
        number(i - 1, n);
    }
}

int main()
{
    int n;
    cout << "Enter value for n: ";
    cin >> n;
    number(n, n);
}
