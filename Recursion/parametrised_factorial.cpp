/*Find the factorial of n numbers using function.

Time Complexity:  O(N)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter the number n: ";
    cin >> n;
    cout << fact(n);
}