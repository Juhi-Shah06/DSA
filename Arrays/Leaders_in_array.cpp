/*Leaders in an Array
Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.
Example 1:
Input: arr = [4, 7, 1, 0]
Output: 7 1 0
Explanation: Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input: arr = [10, 22, 12, 3, 0, 6]
Output: 22 12 6
Explanation: 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.

Time complexity: O(N^2)       [Brute force approach]
Space complexity: O(N)   [considering the worst case where each element is greater than the elements to its right, we will require an extra array to store the answer, therefore we have extra space and complexity is O(N)]

Time complexity: O(N)         [Optimal approach]
Space complexity: O(N)      [If they ask to give the array in sorted order, then space complexity will be O(N log N)]*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
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
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }
        if (leader)
        {
            ans.push_back(arr[i]);
        }
    }
    cout << "Leaders in the array: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// Optimal Approach
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
    int maximum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maximum)
        {
            ans.push_back(arr[i]);
        }
        maximum = max(maximum, arr[i]);
    }
    // sort(ans.begin(), ans.end());       [Use when asked to sort in the ans array]
    cout << "Leaders in the array: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}