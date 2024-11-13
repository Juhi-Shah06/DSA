/*Problem Statement: Given an array and a sum k, we need to
print the length of the longest subarray that sums to k.
Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.
Time complexity: O(N^3) [approx]   Brute force approach
                 O(N)   Better approach
                 O(N)   Optimal approach */

#include <iostream>
#include <unordered_map>
using namespace std;

// Brute force approach
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
    int key;
    cout << "Enter the target sum: ";
    cin >> key;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == key)
                len = max(len, j - i + 1);
        }
    }
    cout << "The longest subarray with sum" << key << " is: " << len;
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
    int key;
    cout << "Enter the target sum: ";
    cin >> key;
    unordered_map<int, int> prefixSumMap;
    int sum = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == key)
        {
            len = i + 1;
        }
        if (prefixSumMap.find(sum - key) != prefixSumMap.end())
        {
            len = max(len, i - prefixSumMap[sum - key]);
        }
        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i;
        }
    }
    cout << "The longest subarray with sum " << key << " is: " << len;
    return 0;
}

// Optimal approach
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
    int k;
    cout << "Enter the target sum: ";
    cin >> k;
    int start = 0;
    int sum = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (sum > k && start <= i)
        {
            sum -= arr[start];
            start++;
        }
        if (sum == k)
        {
            len = max(len, i - start + 1);
        }
    }
    cout << "The longest subarray with sum " << k << " is: " << len;
    return 0;
}
