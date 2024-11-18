/*Merge Overlapping Sub-intervals
Problem Statement: Given an array of intervals, merge all the overlapping intervals
and return an array of non-overlapping intervals.

Example 1:
Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].

[Brute force approach]
Time Complexity: O(N*logN) + O(2*N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N2.
Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.

[Optimal Approach]
Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).
Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
*/

// Brute force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    cout << "Enter the intervals (start and end points): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    cout << "The merged intervals are:\n";
    for (const auto &interval : ans)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}

// Optimal Approach

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    cout << "Enter the intervals (start and end points): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    cout << "The merged intervals are:\n";
    for (const auto &interval : ans)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}