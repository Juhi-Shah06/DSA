/*Insertion Sort

Example:
Input: N = 6
array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52

Time complexity: O()
Space Complexity:
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
    cout << "The unsorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = 0; j < n - 1; j++)
        {
            while (arr[min] < arr[j])
            {
                int temp;
                temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}