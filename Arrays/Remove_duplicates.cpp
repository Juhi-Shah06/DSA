/*Write a program to remove duplicate elements from the array.
Time complexity: O(N)*/

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
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        int k;
        for (k = 0; k <= i; k++)
        {
            if (arr[k] == arr[j])
            {
                break;
            }
        }
        if (k > i)
        {
            arr[++i] = arr[j];
        }
    }
    cout << "The number of unique elements is: " << i + 1 << endl;
    cout << "The unique elements are: ";
    for (int j = 0; j <= i; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}