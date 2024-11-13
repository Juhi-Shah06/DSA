/*Write a program to find factorial of n numbers by using recursion*/
// Time complexity: O(N)
// Space complexity: O(1)

#include <iostream>
using namespace std;

void factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << "The factorial of " << n << " is " << fact;
}

int main()
{
    int n;
    cout << "Enter value for n: ";
    cin >> n;
    factorial(n);
}
