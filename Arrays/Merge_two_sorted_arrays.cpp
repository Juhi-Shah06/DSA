/*Merge two Sorted Arrays Without Extra Space
Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Example 1:
Input:n = 4, arr1[] = [1 4 8 10]
m = 5, arr2[] = [2 3 9]
Output:arr1[] = [1 2 3 4]
arr2[] = [8 9 10]
Explanation:After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.

Example2:
Input:n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]
Output:arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.

[Brute Force Approach]
Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[]. And another O(n+m) is for filling back the two given arrays from arr3[].
Space Complexity: O(n+m) as we use an extra array of size n+m.

[Optimal Solution 1]
Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.
Space Complexity: O(1) as we are not using any extra space.

[Optimal Solution 2]
Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).
Space Complexity: O(1) as we are not using any extra space.
*/

// Brute Force

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the size of first array (n): ";
    cin >> n;
    cout << "Enter the size of second array (m): ";
    cin >> m;

    long long arr1[50], arr2[50], arr3[100];
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    int left = 0, right = 0, index = 0;
    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index++] = arr1[left++];
        }
        else
        {
            arr3[index++] = arr2[right++];
        }
    }
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }
    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }
    cout << "The merged array is: ";
    for (int i = 0; i < n + m; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}

// Optimal Approach 1

int main()
{
    int n, m;
    cout << "Enter the size of first array (n): ";
    cin >> n;
    cout << "Enter the size of second array (m): ";
    cin >> m;

    long long arr1[50], arr2[50];
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    int left = n - 1, right = 0;
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    long long merged[100];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n)
    {
        merged[k++] = arr1[i++];
    }
    while (j < m)
    {
        merged[k++] = arr2[j++];
    }
    cout << "The merged sorted array is: ";
    for (int i = 0; i < n + m; i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;
    return 0;
}

// Optimal Approach 2

int main()
{
    int n, m;
    cout << "Enter the size of first array (n): ";
    cin >> n;
    cout << "Enter the size of second array (m): ";
    cin >> m;

    long long arr1[50], arr2[50];
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    long long merged[100];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        merged[k++] = arr1[i++];
    }

    while (j < m)
    {
        merged[k++] = arr2[j++];
    }

    cout << "The merged sorted array is: ";
    for (int i = 0; i < n + m; i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
