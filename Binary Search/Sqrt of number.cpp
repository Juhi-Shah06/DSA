/*Finding Sqrt of a number using Binary Search
Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

Example 1:
Input Format: n = 36
Result: 6
Explanation: 6 is the square root of 36.

Example 2:
Input Format: n = 28
Result: 5
Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5.

[Brute Force Approach]
Time Complexity: O(N), N = the given number.
Reason: Since we are using linear search, we traverse the entire answer space.
Space Complexity: O(1) as we are not using any extra space.

[Optimal Approach 1]
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using the Binary Search algorithm.
Space Complexity: O(1) as we are not using any extra space.

[Optimal Approach 2]
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using the Binary Search algorithm.
Space Complexity: O(1) as we are not using any extra space.
*/

// Brute Force Approach

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number to find its floor square root: ";
    cin >> n;

    int ans = 0;
    for (long long i = 1; i < n; i++)
    {
        long long val = i * i;
        if (val <= n)
        {
            ans = i;
        }
        else
        
        {
            break;
        }
    }
    cout << "The floor of the square root of " << n << " is: " << ans << "\n";
    return 0;
}

// Optimal approach 1
int main()
{
    int n;
    cout << "Enter a number to find its floor square root: ";
    cin >> n;

    int ans = sqrt(n);

    cout << "The floor of the square root of " << n << " is: " << ans << "\n";
    return 0;
}

// Optimal Approach 2
int main()
{
    int n;
    cout << "Enter a number to find its floor square root: ";
    cin >> n;

    int ans = 1;
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid * mid) <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "The floor of the square root of " << n << " is: " << ans << "\n";
    return 0;
}