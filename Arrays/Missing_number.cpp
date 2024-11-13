/*Problem Statement: Given an integer N and an array of size N-1
containing N-1 numbers between 1 to N. Find the number(between 1 to N),
that is not present in the given array.
Example 1:
Input Format:
N = 5, array[] = {1,2,4,5}
Result: 3
Explanation:
In the given array, number 3 is missing. So, 3 is the answer.
Time complexity : O(N^2)    Brute force approach
                  O(2N)     Better approach
                  O(N)      optimal approach
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[50];
    cout << "Enter " << n - 1 << " numbers: ";
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "The missing number is: " << i << endl;
    }

    return -1;
}

// Optimal approach
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[50];
    cout << "Enter " << n - 1 << " numbers: ";
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> arr[i];
    }
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        arraySum = arraySum + arr[i];
    }

    int missingNumber = totalSum - arraySum;
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}