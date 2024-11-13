/*Longest Consecutive Sequence in an Array
Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.
Example 1:
Input: [100, 200, 1, 3, 2, 4]
Output:  4
Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

Input: [3, 8, 5, 7, 6]
Output: 4
Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.

Time Complexity: O(N^2), N = size of the given array.    [Brute Force Approach]
Reason: We are using nested loops each running for approximately N times.
Space Complexity: O(1), as we are not using any extra space to solve this problem.

Time Complexity: O(NlogN) + O(N), N = size of the given array.   [Better approach]
Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).
Space Complexity: O(1), as we are not using any extra space to solve this problem.

Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.     [Optimal approach]
Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
Space Complexity: O(N), as we are using the set data structure to solve this problem.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

// Brute Force Approach
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[50];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int count = 1;
        bool found = true;
        while (found)
        {
            found = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == x + 1)
                {
                    x += 1;
                    count += 1;
                    found = true;
                    break;
                }
            }
        }
        longest = max(longest, count);
    }
    cout << "The longest consecutive sequence is " << longest << "\n";
    return 0;
}

// // Better Approach
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[50];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 0)
    {
        cout << "The longest consecutive sequence is 0\n";
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    int lastSmaller = 0;
    int cnt = 0;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmaller)
        {
            cnt += 1;
            lastSmaller = arr[i];
        }
        else if (arr[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, cnt);
    }
    cout << "The longest consecutive sequence is " << longest << "\n";
    return 0;
}

// Optimal Approach
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[50];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 0)
    {
        cout << "The longest consecutive sequence is 0\n";
        return 0;
    }
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int longest = 1;
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    cout << "The longest consecutive sequence is " << longest << "\n";
    return 0;
}