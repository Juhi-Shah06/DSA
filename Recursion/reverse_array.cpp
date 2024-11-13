/*Write a program to reverse an array.

Example:
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int N)
{

    int start = 0;
    int end = N - 1;

    while (start < end)
    {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{

    int N = 5;
    int arr[] = {5, 4, 3, 2, 1};

    cout << "Original Array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArray(arr, N);

    cout << "Reversed Array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
