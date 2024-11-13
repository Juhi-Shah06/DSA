/*Median of Two Sorted Arrays of different sizes
Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

Example 1:
Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
Result: 3.5
Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2:
Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
Result: 3
Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.

[Brute Force Approach]
Time Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
Reason: We traverse through both arrays linearly.
Space Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
Reason: We are using an extra array of size (n1+n2) to solve this problem.

[Better Approach]
Time Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
Reason: We traverse through both arrays linearly.
Space Complexity: O(1), as we are not using any extra space to solve this problem.

[Optimal Approach]
Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
Reason: We are applying binary search on the range [0, min(n1, n2)].
Space Complexity: O(1) as no extra space is used.
*/

// Brute Force

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter the number of elements in the first sorted array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter elements of the first sorted array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the number of elements in the second sorted array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter elements of the second sorted array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    vector<int> mergedArr;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            mergedArr.push_back(a[i++]);
        }
        else
        {
            mergedArr.push_back(b[j++]);
        }
    }
    while (i < n1)
    {
        mergedArr.push_back(a[i++]);
    }
    while (j < n2)
    {
        mergedArr.push_back(b[j++]);
    }

    int n = n1 + n2;
    double median;
    if (n % 2 == 1)
    {
        median = (double)mergedArr[n / 2];
    }
    else
    {
        median = ((double)mergedArr[n / 2] + (double)mergedArr[(n / 2) - 1]) / 2.0;
    }
    cout << "The median of the two sorted arrays is: " << median << '\n';
    return 0;
}

// Better Approach

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter the number of elements in the first sorted array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter elements of the first sorted array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the number of elements in the second sorted array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter elements of the second sorted array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    int count = 0;
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int el1 = -1, el2 = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (count == ind1)
                el1 = a[i];
            if (count == ind2)
                el2 = a[i];
            count++;
            i++;
        }
        else
        {
            if (count == ind1)
                el1 = b[j];
            if (count == ind2)
                el2 = b[j];
            count++;
            j++;
        }
    }
    while (i < n1)
    {
        if (count == ind1)
            el1 = a[i];
        if (count == ind2)
            el2 = a[i];
        count++;
        i++;
    }
    while (j < n2)
    {
        if (count == ind1)
            el1 = b[j];
        if (count == ind2)
            el2 = b[j];
        count++;
        j++;
    }

    double median;
    if (n % 2 == 1)
    {
        median = (double)el2;
    }
    else
    {
        median = ((double)(el1 + el2)) / 2.0;
    }
    cout << "The median of the two sorted arrays is: " << median << '\n';
    return 0;
}

// Optimal Approach

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter the number of elements in the first sorted array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter elements of the first sorted array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the number of elements in the second sorted array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter elements of the second sorted array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    if (n1 > n2)
    {
        swap(a, b);
        swap(n1, n2);
    }
    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;
    double median;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                median = max(l1, l2);
            }
            else
            {
                median = (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            break;
        }
        else if (l1 > l2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    cout << "The median of the two sorted arrays is: " << median << '\n';
    return 0;
}