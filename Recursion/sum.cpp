/*Write a program to print sum of n numbers by using recursion*/
// Time complexity: O(N)
// Space complexity: O(1)

#include <iostream>
using namespace std;

void sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << sum;
}

int main()
{
    int n;
    cout << "Enter value for n: ";
    cin >> n;
    sum(n);
}
