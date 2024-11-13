/*Problem Statement: Given a non-empty array of integers arr,
every element appears twice except for one. Find that single one.
Example:
Input Format:
arr[] = {2,2,1}
Result: 1
Explanation:
In this array, only the element 1 appear once and so it is the answer.
Time complexity: O(N^2)   Brute force approach
                 O(N)+O(N)+O(N)  Better approach
                 O(N)     Optimal approach*/

// Brute force approach
#include <iostream>
#include <vector>
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
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << "The number that occurs only once is: " << num << endl;
            break;
        }
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
    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    vector<int> hash(maximum + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            cout << "The element that occurs only once is : " << arr[i] << " ";
        }
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
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    cout << "The element that appears once is: " << xorr << " ";
    return 0;
}