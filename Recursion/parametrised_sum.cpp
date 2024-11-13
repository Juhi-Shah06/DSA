/*Find the sum of n numbers using parametrized function.

Time Complexity:  O(N)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

void f_sum(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    else
    {
        f_sum(i - 1, sum + i);
    }
}

int main()
{
    int n;
    cout << "Enter the number n: ";
    cin >> n;
    f_sum(n, 0);
}

