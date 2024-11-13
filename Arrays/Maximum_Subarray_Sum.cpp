/*Kadane's Algorithm : Maximum Subarray Sum in an Array
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.
Example 1:
Input: arr = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Examples 2:
Input: arr = [1]
Output: 1
Explanation: Array has only one element which is giving positive sum of 1.

Time Complexity: O(N3), where N = size of the array.     [Brute force approach]
Reason: We are using three nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.

Time Complexity: O(N2), where N = size of the array.     [Better approach]
Reason: We are using two nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.

KADANE'S ALGORITHM         [Optimal approach]
Intuition:
The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

Thus we can solve this problem with a single loop.

Approach:
The steps are as follows:
-We will run a loop(say i) to iterate the given array.
-Now, while iterating we will add the elements to the sum variable and consider the maximum one.
-If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

Time Complexity: O(N), where N = size of the array.      [Optimal approach]
Reason: We are using a single loop running N times.
Space Complexity: O(1) as we are not using any extra space.*/

#include <iostream>
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
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maximum = max(maximum, sum);
        }
    }
    cout << "The maximum subarray sum is: " << maximum;
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
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maximum = max(maximum, sum);
        }
    }
    cout << "The maximum subarray sum is: " << maximum;
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
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    int maximum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += arr[i];
        if (sum > maximum)
        {
            maximum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    cout << "The maximum subarray sum is: " << maximum;
    return 0;
}