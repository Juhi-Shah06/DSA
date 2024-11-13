/*Write a program to print numbers from n to 1 by backtracking by using recursion*/
// Time complexity: O(N)
// Space complexity: O(N)

#include <iostream>
using namespace std;

void number(int n, int i)
{
    if (n < i)
    {
        return;
    }
    else
    {
        number(n, i + 1);
        cout << i << " ";
    }
}

int main()
{
    int n;
    cout << "Enter value for n: ";
    cin >> n;
    number(n, 1);
}
