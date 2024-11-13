/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

[Brute Force Approach]
Time Complexity: O(N^2)
Explanation: The brute-force approach uses two nested loops: the outer loop iterates over the starting index i of the subarray, and the inner loop iterates over the ending index j for each starting index i.
For each pair (i, j), we count the number of 0s and 1s in the subarray nums[i:j], which takes O(j-i) operations.
In the worst case, this results in approximately O(N^2) operations, making this solution inefficient for large inputs.
Space Complexity: O(1)
The brute-force approach only requires a few extra variables for counting and does not require any additional data structures.

[Optimal Approach]
Time Complexity: O(n)
Explanation:
We traverse the array once, which takes O(n) time.
During each iteration, we update the cumulative sum and check for its presence in the hash map (average O(1) time for each hash map operation).
Thus, the overall time complexity is O(n).
Space Complexity: O(n)
We store cumulative sums in a hash map, which can have up to n entries in the worst case (each entry is unique).
*/

// Brute Force Approach

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements (0 or 1): ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int maxLength = 0;
    for (int i = 0; i < n; ++i)
    {
        int count0 = 0, count1 = 0;
        for (int j = i; j < n; ++j)
        {
            if (nums[j] == 0)
                count0++;
            else
                count1++;
            if (count0 == count1)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    cout << "Maximum length of contiguous subarray with equal number of 0 and 1: " << maxLength << endl;
    return 0;
}

// Optimal Approach

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements (0 or 1): ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> sumIndexMap;
    sumIndexMap[0] = -1;
    int maxLength = 0;
    int cumulativeSum = 0;
    for (int i = 0; i < n; ++i)
    {
        cumulativeSum += (nums[i] == 0) ? -1 : 1;
        if (sumIndexMap.find(cumulativeSum) != sumIndexMap.end())
        {
            maxLength = max(maxLength, i - sumIndexMap[cumulativeSum]);
        }
        else
        {
            sumIndexMap[cumulativeSum] = i;
        }
    }
    cout << "Maximum length of contiguous subarray with equal number of 0 and 1: " << maxLength << endl;
    return 0;
}
