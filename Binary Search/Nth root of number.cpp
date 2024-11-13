/*Nth Root of a Number using Binary Search
Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

Example 1:
Input Format: N = 3, M = 27
Result: 3
Explanation: The cube root of 27 is equal to 3.

Example 2:
Input Format: N = 4, M = 69
Result: -1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.

[Brute Force Approach]
Time Complexity: O(M), M = the given number.
Reason: Since we are using linear search, we traverse the entire answer space.
Space Complexity: O(1) as we are not using any extra space.

[Optimal Approach]
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.
Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/

// Brute Force Approach

#include <iostream>
using namespace std;

// Power exponential method:
long long powerExponent(int base, int exp)
{
    long long ans = 1;
    long long currentBase = base;
    while (exp > 0)
    {
        if (exp % 2 != 0)
        {
            exp--;
            ans *= currentBase;
        }
        else
        {
            exp /= 2;
            currentBase *= currentBase;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the value of n (root): ";
    cin >> n;
    cout << "Enter the value of m (number): ";
    cin >> m;

    int answer = -1;
    for (int i = 1; i <= m; i++)
    {
        long long value = powerExponent(i, n);
        if (value == m)
        {
            answer = i;
            break;
        }
        else if (value > m)
        {
            break;
        }
    }
    if (answer == -1)
    {
        cout << "No integer root found for " << n << "th root of " << m << endl;
    }
    else
    {
        cout << "The answer is: " << answer << endl;
    }
    return 0;
}

// Optimal Approach

#include <iostream>
using namespace std;

// Helper function to determine if mid^n is equal to, less than, or greater than m
int checkMid(int mid, int n, int m)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= mid;
        if (result > m)
            return 2; // Return 2 if mid^n exceeds m
    }
    if (result == m)
        return 1; // Return 1 if mid^n equals m
    return 0;     // Return 0 if mid^n is less than m
}

int main()
{
    int n, m;
    cout << "Enter the value of n (root): ";
    cin >> n;
    cout << "Enter the value of m (number): ";
    cin >> m;

    int low = 1, high = m, answer = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int check = checkMid(mid, n, m);
        if (check == 1)
        {
            answer = mid;
            break;
        }
        else if (check == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (answer == -1)
    {
        cout << "No integer " << n << "th root found for " << m << endl;
    }
    else
    {
        cout << "The answer is: " << answer << endl;
    }
    return 0;
}
