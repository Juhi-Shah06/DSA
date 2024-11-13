/*Write a program to right rotate then array.
Time complexity:O(N)
Example:
Input: arr[] = {1,2,3,4,5,6,7}
k = 3
Output: arr[] = {5,6,7,1,2,3,4}
*/


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
    int k;
    cout << "Enter the number of places by which you want to right rotate the array: ";
    cin >> k;
    k = k % n;
    
    int temp[50];
    
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }

    for (int i = n - 1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }

    cout << "The rotated array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
