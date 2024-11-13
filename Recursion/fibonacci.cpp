/*Write a program to find the nth fibonacci number.

Example:
Input: n = 2
Output: 1

Time complexity: O(N)
*/

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        int last = fibonacci(n - 1);
        int s_last = fibonacci(n - 2);
        return last + s_last;
    }
}

int main()
{
    int n;
    cout << "Enter which number you want";
    cin >> n;
    cout << fibonacci(n);
    return 0;
}