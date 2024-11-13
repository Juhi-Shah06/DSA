/*Two Sum : Check if a pair with given sum exists in Array
Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice.
Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
    [-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.

Time Complexity: O(N^2), where N = size of the array.             [Brute force approach]
Reason: There are two loops(i.e. nested) each running for approximately N times.
Space Complexity: O(1) as we are not using any extra space.

Time Complexity: O(N), where N = size of the array.               [Better approach]
Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).
Space Complexity: O(N) as we use the map data structure.

Time Complexity: O(N) + O(N*logN), where N = size of the array.   [Optimal approach]
Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.
Space Complexity: O(1) as we are not using any extra space.
*/

// Brute Force Approach
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    vector<int> ans(2, -1);
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans[0] = arr[i]; // ans[0] = i     #to print index
                ans[1] = arr[j]; // ans[1] = j     #to print index
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (ans[0] != -1)
    {
        cout << "The number which sum upto " << target << "are: " << ans[0] << " and " << ans[1] << endl;
    }
    else
    {
        cout << "No numbers in the array add upto" << target;
    }
    return 0;
}

// Better approach
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
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    unordered_map<int, int> mpp;
    vector<int> ans(2, -1);
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int required = target - num;
        if (mpp.find(required) != mpp.end())
        {
            ans[0] = mpp[required];
            ans[1] = i;
            flag = 1;
            break;
        }
        mpp[num] = i;
    }
    if (flag)
    {
        cout << "The two numbers that sum up to " << target << " are: " << ans[0] << " and " << ans[1] << endl;
    }
    else
    {
        cout << "No two numbers found in the array that sum up to " << target << endl;
    }
    return 0;
}

// Optimal approach
int main()
{
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    string result = "NO"; 
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            result = "YES";
            break; 
        }
        else if (sum < target)
        {
            left++; 
        }
        else
        {
            right--; 
        }
    }
    cout << "This is the answer for variant 1: " << result << endl;
    return 0;
}
