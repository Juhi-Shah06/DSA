/*Find the sum of n numbers using function.

Time Complexity:  O(N)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter the number n: ";
    cin >> n;
    cout << sum(n);
}