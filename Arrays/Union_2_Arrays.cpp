/*Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m.
Find the union of two sorted arrays.
Example 1:
Input:
n = 5,m = 5.
arr1[] = {1,2,3,4,5}
arr2[] = {2,3,4,4,5}
Output:{1,2,3,4,5}
Time complexity: O((m+n)log(m+n))   Brute force approach
                 O(m+n)             Two pointer approach
*/

#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter the number of elements in 2 arrays: ";
    cin >> n1 >> n2;
    int arr1[50], arr2[50];
    cout << "Enter the elements in the array1: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the elements in the array1: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    
}
