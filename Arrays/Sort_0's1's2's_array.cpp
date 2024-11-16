/*Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Output: [0]

[Brute Force approach]
Time Complexity: O(N*logN)         
Space Complexity: O(1)

[Better approach]
Time Complexity: O(N) + O(N), where N = size of the array.       
First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.
Space Complexity: O(1) as we are not using any extra space.

DUTCH NATIONAL FLAG ALGORITHM
[Optimal approach]
Time Complexity: O(N), where N = size of the given array.        
Reason: We are using a single loop that can run at most N times.
Space Complexity: O(1) as we are not using any extra space.*/


#include <iostream>
using namespace std;

//Brute force approach
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
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "The sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_0++;
        }
        else if (arr[i] == 1)
        {
            count_1++;
        }
        else
        {
            count_2++;
        }
    }
    for (int i = 0; i < count_0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count_0; i < count_0 + count_1; i++)
    {
        arr[i] = 1;
    }
    for (int i = count_0 + count_1; i < n; i++)
    {
        arr[i] = 2;
    }
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
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
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


