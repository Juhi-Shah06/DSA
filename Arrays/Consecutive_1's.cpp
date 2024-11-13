/*Problem Statement: Given an array that contains only 1 and 0
return the count of maximum consecutive ones in the array.
Example 1:
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive
             1’s in the array out of which maximum is 3.
Time complexity:O(N) */

#include <iostream>
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
    int count = 0;
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maximum = max(maximum, count);
    }
    cout << "The maximum number of consecutive 1's are: " << maximum;
    return 0;
}